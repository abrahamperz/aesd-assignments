/*
 * writer.c - AESD Assignment 2
 *
 * A C alternative to the assignment 1 writer.sh script.
 * Writes a string to a file using File IO (LSP chapter 2) and logs via syslog.
 *
 * Usage: writer <writefile> <writestr>
 *   writefile : full path (including filename) of the file to write.
 *               The containing directory is assumed to already exist.
 *   writestr  : text string written into writefile (overwrites existing content).
 *
 * Exit status: 0 on success, 1 on any error.
 */

#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>

int main(int argc, char *argv[])
{
    /* Set up logging with the LOG_USER facility. */
    openlog("writer", LOG_PID, LOG_USER);

    /* Both arguments are required. */
    if (argc != 3) {
        syslog(LOG_ERR,
               "Invalid number of arguments: expected 2 (writefile writestr), got %d",
               argc - 1);
        fprintf(stderr, "Error: two arguments are required: writefile and writestr\n");
        closelog();
        return 1;
    }

    const char *writefile = argv[1];
    const char *writestr  = argv[2];

    /* Open (create/truncate) the file for writing. */
    FILE *fp = fopen(writefile, "w");
    if (fp == NULL) {
        syslog(LOG_ERR, "Could not open file %s for writing", writefile);
        fprintf(stderr, "Error: could not create file '%s'\n", writefile);
        closelog();
        return 1;
    }

    /* Required debug log message. */
    syslog(LOG_DEBUG, "Writing %s to %s", writestr, writefile);

    /* Write the content. */
    if (fputs(writestr, fp) == EOF) {
        syslog(LOG_ERR, "Error writing to file %s", writefile);
        fprintf(stderr, "Error: could not write to file '%s'\n", writefile);
        fclose(fp);
        closelog();
        return 1;
    }

    if (fclose(fp) != 0) {
        syslog(LOG_ERR, "Error closing file %s", writefile);
        fprintf(stderr, "Error: could not close file '%s'\n", writefile);
        closelog();
        return 1;
    }

    closelog();
    return 0;
}
