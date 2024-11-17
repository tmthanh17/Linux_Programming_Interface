#ifndef ERROR_FUNCTIONS_H
#define ERROR_FUNCTIONS_H

/*Function prints the error text corre
sponding to the current value of errno*/
void errMsg(const char *format, ...);

#ifdef __GNUC__
 /* This macro stops 'gcc -Wall' complaining that "control reaches
     end of non-void function" if we use the following functions to
     terminate main() or some other non-void function. */
#define NORETURN __attribute__ ((__noreturn__))
#else
#define NORETURN
#endif

/*Function operates like errMsg(), but also terminates the program,either by calling exit() or, 
 if the environment variable EF_DUMPCORE is defined with a nonempty string value, by calling abort() 
 to produce a core dump file for use with the debugger.*/
void errExit(const char *format, ...) NORETURN;

/*Function is similar to errExit(), but differs in two respects:
 It doesn’t flush standard output before printing the error message.
 It  causes the process to terminate without flushing stdio buffers or invoking exit handlers.*/
void err_exit(const char *format, ...) NORETURN;

/*Function prints the text corresponding to the error number (thus, the EN suffix) given in the argument errnum.*/
void errExitEN(int errnum, const char *format, ...) NORETURN;

/*Function is used to diagnose general errors, including errors from
 library functions that don’t set errno.*/
void fatal(const char *format, ...) NORETURN;

/*Function is used to diagnose errors in command-line argument
 usage.*/
void usageErr(const char *format, ...) NORETURN;

/*Function is similar to usageErr(), but is intended for diagnosing
 errors in the command-line arguments specified to a program.*/
void cmdLineErr(const char *format, ...) NORETURN;

#endif;
