//
//  BRTransaction.h
//  breadwallet-core
//
//  Created by Aaron Voisine on 8/31/15.
//  Copyright (c) 2015 breadwallet LLC
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//  THE SOFTWARE.

#ifndef BRTransaction_h
#define BRTransaction_h

#include "BRTypes.h"
#include <stddef.h>

typedef struct {
    UInt256 txHash;
    uint32_t index;
    const uint8_t *script;
    size_t scriptLen;
    const uint8_t *signature;
    size_t sigLen;
    uint32_t sequence;
} BRTxInput;

typedef struct {
    uint64_t amount;
    const uint8_t *script;
    size_t scriptLen;
} BRTxOutput;

typedef struct {
    uint32_t version;
    size_t inCount;
    BRTxInput *inputs;
    size_t outCount;
    BRTxOutput *outputs;
    uint32_t lockTime;
    UInt256 txHash;
    uint32_t blockHeight;
    uint32_t timestamp; // time interval since unix epoch
} BRTransaction;

// returns a newly allocated empty transaction that must be freed by calling BRTransactionFree()
BRTransaction *BRTransactionCreate(void *(*alloc)(size_t));

// buf must contain a serialized tx, result must be freed by calling BRTransactionFree()
BRTransaction *BRTransactionDeserialize(void *(*alloc)(size_t), const uint8_t *buf, size_t len);

// returns number of bytes written to buf, or total size needed if buf is NULL
size_t BRTransactionSerialize(BRTransaction *tx, uint8_t *buf, size_t len);

// adds an input to tx
int BRTransactionAddInput(BRTransaction *tx, void *(*realloc)(void *, size_t), BRTxInput *input);

// adds an output to tx
int BRTransactionAddOutput(BRTransaction *tx, void *(*realloc)(void *, size_t), BRTxOutput *output);

// shuffles order of tx outputs
void BRTransactionShuffleOutputs(BRTransaction *tx);

// adds signatures to any inputs with NULL signatures that can be signed with any privKeys
void BRTransactionSign(BRTransaction *tx, void *(*alloc)(size_t), const char *privKeys[], size_t count);

// frees memory allocated for tx
void BRTransactionFree(BRTransaction *tx, void (*free)(void *));

#endif // BRTransaction_h