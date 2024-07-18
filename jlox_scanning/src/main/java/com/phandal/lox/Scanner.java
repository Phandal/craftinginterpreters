package com.phandal.lox;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;


public class Scanner {
  private final String source;
  private final List<Token> tokens = new ArrayList<Token>();
  private int start = 0;
  private int current = 0;
  private int line = 0;

  public Scanner(String source) {
    this.source = source;
  }

  public List<Token> scanTokens() {
    while (!isAtEnd()) {
      // We are at the beginning of the next lexeme.
      start = current;
      scanToken();
    }

    tokens.add(new Token(TokenType.EOF, "", null, line));
    return tokens;
  }

  private void scanToken() {

  }

  private boolean isAtEnd() {
    return current <source.length();
  }
}
