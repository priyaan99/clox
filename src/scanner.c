#include <stdio.h>
#include <string.h>

#include "common.h"
#include "scanner.h"

typedef struct {
	const char* start;
	const char* current;
	int line;
} Scanner;

Scanner scanner;

void init_scanner(const char* source) {
	scanner.start = source;
	scanner.current = source;
	scanner.line = 1;
	return;
}

static bool is_at_end() {
	return *scanner.current == '\0';
}

static char advance() {
	scanner.current++;
	return scanner.current[-1];
}

static Token make_token(TokenType type) {
	Token token;
	token.type = type;
	token.start = scanner.start;
	token.length = (int)(scanner.current - scanner.start);
	token.line = scanner.line;
	return token;
}

static Token error_token(const char* message) {
	Token token;
	token.type = TOKEN_ERROR;
	token.start = message;
	token.length = (int)strlen(message); 
	token.line = scanner.line;
	return token;
}

Token scan_token() {
	scanner.start = scanner.current;

	if (is_at_end()) return make_token(TOKEN_EOF);

	char c = advance();

	switch (c) {
		case '(': return make_token(TOKEN_LEFT_PAREN);
		case ')': return make_token(TOKEN_RIGHT_PAREN);
		case '{': return make_token(TOKEN_LEFT_BRACE);
		case '}': return make_token(TOKEN_RIGHT_BRACE);
		case ';': return make_token(TOKEN_SEMICOLON);
		case ',': return make_token(TOKEN_COMMA);
		case '.': return make_token(TOKEN_DOT);
		case '-': return make_token(TOKEN_MINUS);
		case '+': return make_token(TOKEN_PLUS);
		case '/': return make_token(TOKEN_SLASH);
		case '*': return make_token(TOKEN_STAR);
	}

	return error_token("Unexpected character.");
}
