#pragma once

#include <string.h>
#include <ren/Global.h>
#include <ren/ID.h>
#include <ren/Type.h>
#include <ren/Function.h>

namespace ren {

    class ExpressionWalker {
    public:
        virtual void pushInput(const ID& id, Frequency frequency, Type type) = 0;
        virtual void pushInt(int i) = 0;
        virtual void pushFloat(float f) = 0;
        virtual void multiply() = 0;
        virtual void add() = 0;
        virtual void swizzle(const char* swizzle) = 0;
        virtual void index() = 0;
        virtual void apply(const FunctionBase* function, unsigned argCount) = 0;
    };

    REN_PTR(Expression);

    inline Frequency getMaximumFrequency(const std::vector<ExpressionPtr>& operands);

    class Expression {
    public:
        Expression(Type type, Frequency frequency)
            : type(type)
            , frequency(frequency)
        {}

        Expression(Type type, const std::vector<ExpressionPtr>& operands)
            : type(type)
            , frequency(getMaximumFrequency(operands))
            , operands(operands)
        {}

        const Type type;
        const Frequency frequency;
        const std::vector<ExpressionPtr> operands;

        virtual void walk(ExpressionWalker& w) = 0;
    };

    inline Frequency getMaximumFrequency(const std::vector<ExpressionPtr>& operands) {
        verify(!operands.empty());
        Frequency result = operands[0]->frequency;
        for (size_t i = 1; i < operands.size(); ++i) {
            result = std::max(result, operands[i]->frequency);
        }
        return result;
    }

    class Multiply : public Expression {
    public:
        Multiply(Type type, const ExpressionPtr& left, const ExpressionPtr& right)
            : Expression(type, {left, right})
        {}

        void walk(ExpressionWalker& w) {
            w.multiply();
        }

    private:
        Multiply() = delete;
    };

    class Add : public Expression {
    public:
        Add(Type type, const ExpressionPtr& left, const ExpressionPtr& right)
            : Expression(type, {left, right})
        {}

        void walk(ExpressionWalker& w) {
            w.add();
        }

    private:
        Add() = delete;
    };

    class InputExpression : public Expression {
    public:
        InputExpression(const ID& id, Type type, Frequency frequency)
            : Expression(type, frequency)
            , id(id)
        {}

        const ID id;

        void walk(ExpressionWalker& w) {
            w.pushInput(id, frequency, type);
        }
    };

    class IntLiteral : public Expression {
    public:
        explicit IntLiteral(int i)
            : Expression(Type::scalar(Type::INT), CONSTANT)
            , i(i)
        {}

        void walk(ExpressionWalker& w) {
            w.pushInt(i);
        }

    private:
        int i;
    };

    class FloatLiteral : public Expression {
    public:
        explicit FloatLiteral(float f)
            : Expression(Type::scalar(Type::FLOAT), CONSTANT)
            , f(f)
        {}

        void walk(ExpressionWalker& w) {
            w.pushFloat(f);
        }

    private:
        float f;
    };

    class Swizzle : public Expression {
    public:
        Swizzle(const ExpressionPtr& base, const char* swizzle)
            : Expression(Type::vector(base->type.element_type, strlen(swizzle)), {base})
            , swizzle(swizzle)
        {}

        void walk(ExpressionWalker& w) {
            w.swizzle(swizzle);
        }

        const char* const swizzle;
    };

    class Index : public Expression {
    public:
        Index(const ExpressionPtr& base, const ExpressionPtr& index)
            : Expression(base->type.withoutArray(), {base, index})
        {}

        void walk(ExpressionWalker& w) {
            w.index();
        }
    };

    class FunctionCall : public Expression {
    public:
        FunctionCall(const FunctionBase* fn, const ExpressionPtr& a0, const ExpressionPtr& a1)
            : Expression(fn->signature.result, {a0, a1})
            , function(fn)
        {
        }

        FunctionCall(const FunctionBase* fn, const ExpressionPtr& a0, const ExpressionPtr& a1, const ExpressionPtr& a2)
            : Expression(fn->signature.result, {a0, a1, a2})
            , function(fn)
        {
        }

        FunctionCall(const FunctionBase* fn, const ExpressionPtr& a0, const ExpressionPtr& a1, const ExpressionPtr& a2, const ExpressionPtr& a3)
            : Expression(fn->signature.result, {a0, a1, a2, a3})
            , function(fn)
        {
        }

        void walk(ExpressionWalker& w) {
            w.apply(function, operands.size());
        }

        const FunctionBase* const function;
    };

}

