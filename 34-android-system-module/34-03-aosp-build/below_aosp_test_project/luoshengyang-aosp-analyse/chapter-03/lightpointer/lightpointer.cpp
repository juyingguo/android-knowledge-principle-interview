#include <stdio.h>
#include <utils/RefBase.h>

using namespace android;

class LightClass : public LightRefBase<LightClass>
{
public:
    LightClass()
    {
        printf("Construct LightClass Object.");
    }

    virtual ~LightClass()
    {
        printf("Destory LightClass Object.");
    }
};

int main(int argc, char** argv)
{
    LightClass* pLightClass = new LightClass();
    sp<LightClass> lpOut = pLightClass;

    printf("Light Ref Count:%d.\n", pLightClass->getStrongCount());

    {
        sp<LightClass> lpInner = lpOut;
        printf("Light Ref Count:%d.\n", pLightClass->getStrongCount());
    }

    printf("Light Ref Count:%d.\n", pLightClass->getStrongCount());

    return 0;
}
