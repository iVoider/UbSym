/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE121_Stack_Based_Buffer_Overflow__CWE805_char_declare_memmove_32.c
Label Definition File: CWE121_Stack_Based_Buffer_Overflow__CWE805.string.label.xml
Template File: sources-sink-32.tmpl.c
*/
/*
 * @description
 * CWE: 121 Stack Based Buffer Overflow
 * BadSource:  Set data pointer to the bad buffer
 * GoodSource: Set data pointer to the good buffer
 * Sink: memmove
 *    BadSink : Copy string to data using memmove
 * Flow Variant: 32 Data flow using two pointers to the same value within the same function
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

void CWE121_Stack_Based_Buffer_Overflow__CWE805_char_declare_memmove_32_bad(char * source)
{
    char * data;
    char * *dataPtr1 = &data;
    char * *dataPtr2 = &data;
    char dataBadBuffer[50];
    char dataGoodBuffer[100];
    {
        char * data = *dataPtr1;
        /* FLAW: Set a pointer to a "small" buffer. This buffer will be used in the sinks as a destination
         * buffer in various memory copying functions using a "large" source buffer. */
        data = dataBadBuffer;
        data[0] = '\0'; /* null terminate */
        *dataPtr1 = data;
    }
    {
        char * data = *dataPtr2;
        {
            /* POTENTIAL FLAW: Possible buffer overflow if the size of data is less than the length of source */
            if (source[0] == '7' && source[1] == '/' && source[2] == '4'
	    && source[3] == '2' && source[4] == 'a' && source[5] == '8' && source[75] == 'a') 
            {
	        memmove(data, source, strlen(source)*sizeof(char));
	    }
            printLine(data);
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B(char * source)
{
    char * data;
    char * *dataPtr1 = &data;
    char * *dataPtr2 = &data;
    char dataBadBuffer[50];
    char dataGoodBuffer[100];
    {
        char * data = *dataPtr1;
        /* FIX: Set a pointer to a "large" buffer, thus avoiding buffer overflows in the sinks. */
        data = dataGoodBuffer;
        data[0] = '\0'; /* null terminate */
        *dataPtr1 = data;
    }
    {
        char * data = *dataPtr2;
        {
            /* POTENTIAL FLAW: Possible buffer overflow if the size of data is less than the length of source */
            memmove(data, source, 100*sizeof(char));
            data[100-1] = '\0'; /* Ensure the destination buffer is null terminated */
            printLine(data);
        }
    }
}

void CWE121_Stack_Based_Buffer_Overflow__CWE805_char_declare_memmove_32_good(char * source)
{
    goodG2B(source);
}

#endif /* OMITGOOD */

/* Below is the main(). It is only used when building this testcase on
 * its own for testing or for building a binary to use in testing binary
 * analysis tools. It is not used when compiling all the testcases as one
 * application, which is how source code analysis tools are tested.
 */



int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    CWE121_Stack_Based_Buffer_Overflow__CWE805_char_declare_memmove_32_good(argv[1]);
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE121_Stack_Based_Buffer_Overflow__CWE805_char_declare_memmove_32_bad(argv[1]);
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

