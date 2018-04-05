#define _DEFAULT_SOURCE
#define _BSD_SOURCE
#define _GNU_SOURCE

#include "term.h"
#include "memBuffer.h"
#include "fileIO.h"
#include "find.h"
#include "editor.h"
#include "input.h"
#include "output.h"
#include "row.h"
#include "version.h"
#include "commandLine.h"
#include "global.h"

#include <stdio.h>
#include <stdlib.h>

void initEditor(void);

int main(int argc, char *argv[])
{
    globalVars_t *glob = processCommandLineArgs(argc, argv);

    enableRawMode();
    initEditor();
    if (argc >= 2) {
        editorOpen(argv[1]);
    }
    editorSetStatusMessage("[Ctrl-S] Save | [Ctrl-F] Find | [Ctrl-Q] Quit");

    /* Refresh per key press until exit */
    for (;;) {
        editorRefreshScreen();
        editorProcessKeypress();
    }

    return 0;
}
