package com.phandal.lox;

/*
 * This enum is taken from "sysexit.h"
 */

public enum SysExit {
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
