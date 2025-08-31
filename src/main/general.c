#include "../../include/main/general.h"
#include "../../include/main/vecf.h"
#include "../../include/main/shapes.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

static float arg1 = 0.0f;
static float arg2 = 0.0f;
static float result = 0.0f;

static float ftemp = 0.0f;

static char confText[120];
static int confLine = 1;

static bool showmem = false;
static int memUsage = sizeof(arg1) + sizeof(arg2) + sizeof(result) + sizeof(confText) + sizeof(confLine) + sizeof(showmem) + sizeof(memUsage) + sizeof(r) + sizeof(y) + sizeof(V) + sizeof(areaX) + sizeof(areaZ) + sizeof(base) + sizeof(area) + sizeof(baseline);

static void readpref(){
    FILE *file = fopen("../../etc/pref.conf", "r");
    if(file){
        while (fgets(confText, sizeof(confText), file)) {
            if(confLine == 1){
                if(confText[11] == 'Y' || confText[11] == 'y'){
                    showmem = true;
                }else if(confText[11] == 'N' || confText[11] == 'n'){

                }else{
                    printf("CONF ERROR: Invalid value for SHOWMEM (line 1)");
                }
            }
        }
        fclose(file);
    }
}