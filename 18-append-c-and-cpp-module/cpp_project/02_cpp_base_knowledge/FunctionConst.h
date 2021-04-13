/*
 * FunctionConst.h
 */

#ifndef FUNCTIONCONST_H_
#define FUNCTIONCONST_H_

class FunctionConst {
public:
    int value;
    FunctionConst();
    virtual ~FunctionConst();
    const int getValue();
    int getValue2() const;
};

#endif /* FUNCTIONCONST_H_ */
