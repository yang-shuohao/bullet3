
#include <gtest/gtest.h>

#include "Bullet3Common/b3Logging.h"


void myerrorprintf(const char* msg)
{
	printf(msg);
}
	
static bool sVerboseWarning = false;

void mywarningprintf(const char* msg)
{
	if (sVerboseWarning)
	{
		//OutputDebugStringA(msg);
		printf(msg);
	}
}

static bool sVerbosePrintf=false;

void myprintf(const char* msg)
{
	if (sVerbosePrintf)
	{
		//OutputDebugStringA(msg);
		printf(msg);
	}
}

int gArgc=0;
char** gArgv=0;


int main(int argc, char **argv) {
#if _MSC_VER
        _CrtSetDbgFlag ( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );
        //void *testWhetherMemoryLeakDetectionWorks = malloc(1);
#endif
        ::testing::InitGoogleTest(&argc, argv);

		gArgc = argc;
		gArgv = argv;

		b3SetCustomPrintfFunc(myprintf);
		b3SetCustomWarningMessageFunc(mywarningprintf);
		b3SetCustomErrorMessageFunc(myerrorprintf);

        return RUN_ALL_TESTS();
}
