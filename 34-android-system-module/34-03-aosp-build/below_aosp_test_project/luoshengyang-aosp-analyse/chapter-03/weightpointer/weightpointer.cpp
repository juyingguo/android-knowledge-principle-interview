#include <stdio.h>
#include <utils/RefBase.h>

#define INITIAL_STRONG_VALUE (1<<28)

using namespace android;

class WeightClass : public RefBase
{
public:
    void printRefCount() {
        int32_t strong = getStrongCount();
        weakref_type* ref = getWeakRefs();
        printf("printRefCount-----------start.\n");
        printf("printRefCount Strong Ref Count: %d.\n", (strong == INITIAL_STRONG_VALUE) ? 0 : strong);
        printf("printRefCount Weak Ref Count: %d.\n", ref->getWeakCount());
        printf("printRefCount------------end.\n");
    }
};

class StrongClass : public WeightClass
{
public:
    StrongClass() {
        printf("Construct StrongClass Object.\n");
    }

    virtual ~StrongClass() {
        printf("Destory StrongClass Object.\n");
    }
};

class WeakClass : public WeightClass
{
public:
    WeakClass() {
        extendObjectLifetime(OBJECT_LIFETIME_WEAK);
        printf("Construct WeakClass Object.\n");
    }

    virtual ~WeakClass() {
        printf("Destory WeakClass Object.\n");
    }
};
class ForeverClass :public WeightClass
{
public :
	ForeverClass(){
		extendObjectLifetime(OBJECT_LIFETIME_FOREVER);
	       printf("Construct ForeverClass Object.\n");
	}

	virtual ~ForeverClass(){
	       printf("Destory ForeverClass Object.\n");
	}
};

void testStrongClass(StrongClass* pStrongClass) {
    wp<StrongClass> wpOut = pStrongClass;
    pStrongClass->printRefCount();

    {
        sp<StrongClass> spInner = pStrongClass;
        pStrongClass->printRefCount();
    }
	pStrongClass->printRefCount();
    sp<StrongClass> spOut = wpOut.promote();
    printf("testStrongClass spOut:%p.\n", spOut.get());
}

void testWeakClass(WeakClass* pWeakClass) {
    wp<WeakClass> wpOut = pWeakClass;
    pWeakClass->printRefCount();

    {
        sp<WeakClass> spInner = pWeakClass;
        pWeakClass->printRefCount();
    }

    pWeakClass->printRefCount();
    sp<WeakClass> spOut = wpOut.promote();
    printf("testWeakClass spOut: %p.\n", spOut.get());
}
void testForeverClass(ForeverClass * pForeverClass){
	wp<ForeverClass> wpOut = pForeverClass;
	pForeverClass->printRefCount();

	{
		sp<ForeverClass> spInner= pForeverClass;
		pForeverClass->printRefCount();
	}
	

}

int main(int argc, char** argv)
{
    printf("main Test Strong Class: \n");
    StrongClass* pStrongClass = new StrongClass();
    testStrongClass(pStrongClass);

    printf("main Test Weak Class: \n");
    WeakClass* pWeakClass = new WeakClass();
    testWeakClass(pWeakClass);


	printf("main Test Forever Class: \n");
	ForeverClass* pForeverClass = new ForeverClass();
   testForeverClass(pForeverClass);
	pForeverClass->printRefCount();
	delete pForeverClass;
    return 0;
}
