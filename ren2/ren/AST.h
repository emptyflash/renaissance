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

    class Expression {
    public:
        Expression(Type type, const std::vector<ExpressionPtr>& operands = std::vector<ExpressionPtr>())
            : type(type)
            , operands(operands)
        {}

        const Type type;
        const std::vector<ExpressionPtr> operands;

        virtual void walk(ExpressionWalker& w) = 0;
    };

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

    class ConstantExpression : public Expression {
    public:
        ConstantExpression(const ID& id, Type type)
            : Expression(type)
            , id(id)
        {}

        const ID id;

        void walk(ExpressionWalker& w) {
            w.pushInput(id, CONSTANT, type);
        }
    };

    class UniformExpression : public Expression {
    public:
        UniformExpression(const ID& id, Type type)
            : Expression(type)
            , id(id)
        {}

        const ID id;

        void walk(ExpressionWalker& w) {
            w.pushInput(id, UNIFORM, type);
        }
    };

    class AttributeExpression : public Expression {
    public:
        AttributeExpression(const ID& id, Type type)
            : Expression(type)
            , id(id)
        {}

        const ID id;

        void walk(ExpressionWalker& w) {
            w.pushInput(id, ATTRIBUTE, type);
        }
    };

    class IntLiteral : public Expression {
    public:
        explicit IntLiteral(int i)
            : Expression(Type::scalar(Type::INT))
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
            : Expression(Type::scalar(Type::FLOAT))
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
        FunctionCall(Type type, const FunctionBase* fn, const ExpressionPtr& a0, const ExpressionPtr& a1)
            : Expression(type, {a0, a1})
            , function(fn)
        {
        }

        FunctionCall(Type type, const FunctionBase* fn, const ExpressionPtr& a0, const ExpressionPtr& a1, const ExpressionPtr& a2, const ExpressionPtr& a3)
            : Expression(type, {a0, a1, a2, a3})
            , function(fn)
        {
        }

        void walk(ExpressionWalker& w) {
            w.apply(function, operands.size());
        }

        const FunctionBase* const function;
    };

}

