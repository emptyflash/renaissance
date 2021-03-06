#include <fstream>
#include <ren/ShaderLexer.hpp>
#include <ren/ShaderParser.hpp>
using namespace ren;


int usage() {
    std::cerr << "Usage: testParser filename" << std::endl;
    return -1;
}


int main(int argc, char** argv) {
    if (argc != 2) {
        return usage();
    }

    std::ifstream shader(argv[1]);
    if (!shader) {
        std::cerr << "File '" << argv[1] << "' does not exist." << std::endl;
        return usage();
    }

    try {
        antlr::ASTFactory factory;
        ShaderLexer lexer(shader);
        ShaderParser parser(lexer);

        parser.initializeASTFactory(factory);
        parser.setASTFactory(&factory);

        parser.program();

        if (antlr::RefAST ast = parser.getAST()) {
            //std::cout << ast->toStringList() << std::endl
            //          << "----" << std::endl;

            do {
                std::cout << ast->toStringTree() << std::endl;
                ast = ast->getNextSibling();
            } while (ast);
        } else {
            std::cerr << "No AST built!" << std::endl;
        }
    }
    catch (const antlr::ANTLRException& e) {
        std::cerr << "ANTLR Exception: " << e.toString() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}
