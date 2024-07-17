package com.phandal.lox;

enum SysExit {
    ES_OK(0),
    EX_USAGE(64),
    EX_DATAERR(65);

    private int code;

    private SysExit(int code) {
        this.code = code;
    }

    public int getCode() {
        return this.code;
    }
}
