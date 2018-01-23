//
// Created by Sam on 2018/1/17.
//

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "parser.h"
#include "parseExpression.h"
#include "parseExpressionRD.h"

/**
 * @brief 创建语法解析器
 * @param tokenizer 词法分析器
 * @return 解析器
 */
ParserT *newParser(TokenizerT *tokenizer) {
    ParserT *parser = (ParserT *) malloc(sizeof(ParserT));
    parser->tokenizer = tokenizer;
    parser->currToken = NULL;
    parser->parserStateType = PARSER_CORRECT;
    return parser;
};

/**
 * @brief 获取下一个token，如果当前的token不为NULL，则不获取下一个token。
 * 如果解析出错则返回NULL,停止解析
 * @param parser 解析器
 * @return Token
 */
TokenT *parseNextToken(ParserT *parser) {
    if (parser->parserStateType == PARSER_WRONG) {
        return NULL;
    }
    if (parser->currToken == NULL) {
        parser->currToken = TKGetNextToken(parser->tokenizer);
    }
    return parser->currToken;
};

/**
 * @brief 处理完一个token后，需要调用此方法把token销毁。
 * @param parser  解析器
 * @return  NULL
 */
TokenT *parseEatToken(ParserT *parser) {
    if (parser->parserStateType == PARSER_WRONG) {
        return NULL;
    }
    parser->currToken = NULL;
    return NULL;
};

/**
 * @brief eat掉当前的token，并获取下一个token
 * @param parser
 * @return
 */
TokenT *parseEatAndNextToken(ParserT *parser) {
    if (parser->parserStateType == PARSER_WRONG) {
        return NULL;
    }
    parser->currToken = TKGetNextToken(parser->tokenizer);
    return parser->currToken;
};

/**
 * @brief 产生解析错误
 * @param parser 解析器
 * @param message 错误消息
 * @return NULL
 */
void *parseError(ParserT *parser, char *message) {
    strcpy(parser->parserMessage, message);
    parser->parserStateType = PARSER_WRONG;
    return NULL;
};


CreateStmt *parseCreate(ParserT *parser) { return NULL; };

AlterStmt *parseAlter(ParserT *parser) { return NULL; };

DeleteStmt *parseDelete(ParserT *parser) { return NULL; };

UpdateStmt *parseUpdate(ParserT *parser) { return NULL; };


TermExpr *parseTermExpr(ParserT *parser) { return NULL; };

BinaryExpr *parseBinaryExpr(ParserT *parser) { return NULL; };

UnaryExpr *parseUnaryExpr(ParserT *parser) { return NULL; };

GroupExpr *parseGroupExpr(ParserT *parser) { return NULL; };

OrderExpr *parseOrderExpr(ParserT *parser) { return NULL; };

ColumnsExpr *parseColumnsExpr(ParserT *parser) { return NULL; };

SetExpr *parseSetExpr(ParserT *parser) { return NULL; };

