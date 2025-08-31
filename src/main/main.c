#include <stdio.h>
#include <stdbool.h>
#include "../../include/main/vecf.h"
#include "../../include/main/shapes.h"
#include "../../include/main/general.h"

int main(){
    vecf results;
    vecf_init(&results, 10);

    bool pause = false;
    char* input = NULL;
    char* shape = NULL;

    int counter = 0;

    while(!pause){
        if(counter >= vecf_size(&results) || counter >= vecf_capacity(&results)){
            vecf_resize(&results, vecf_capacity(&results) + 5);
        }

        if(showmem){
            printf("                                                            MEM: %d\n", memUsage);
        }

        printf("OP:> ");
        scanf("%s", input);
        if(input == "exit" || input == ":q"){
            pause = true;
            break;
        }
        else if(input == "shape"){
            printf("SHAPE:> ");
            scanf("%s", shape);
            if(shape == "circle"){
                printf("RADIUS:> ");
                scanf("%f", &r);
                result = area_circle(r);
            }else if(shape == "cone"){
                printf("RADIUS:> ");
                scanf("%f", &r);
                printf("HEIGHT:> ");
                scanf("%f", &y);
                result = vol_cone(r, y);
            }else if(shape == "cube"){
                printf("BASELINE:> ");
                scanf("%f", &baseline);
                result = vol_cube(baseline);
            }else if(shape == "cylinder"){
                printf("RADIUS:> ");
                scanf("%f", &r);
                printf("HEIGHT:> ");
                scanf("%f", &y);
                result = vol_cylinder(r, y);
            }else if(shape == "pyramid"){
                printf("SIDE X:> ");
                scanf("%f", &areaX);
                printf("SIDE Z:> ");
                scanf("%f", &areaZ);
                printf("HEIGHT:> ");
                scanf("%f", &y);
                result = vol_pyramid(areaX, areaZ, y);
            }else if(shape == "sphere"){
                printf("RADIUS:> ");
                scanf("%f", &r);
                result = vol_sphere(r);
            }else if(shape == "triangle"){
                printf("BASE:> ");
                scanf("%f", &base);
                printf("HEIGHT:> ");
                scanf("%f", &y);
                result = area_triangle(base, y);
            }else{
                printf("INVALID SHAPE");
            }
        }else if(input == "results"){
            for(int i = 0; i < vecf_size(&results); i++){
                printf("%f, ", vecf_at(&results, i));
            }
        }
        printf("ARG1:> ");
        scanf("%f", &arg1);
        printf("ARG:2> ");
        scanf("%f", &arg2);
        if(input == "+"){
            result = arg1 + arg2;
        }else if(input == "-"){
            result = arg1 - arg2;
        }else if(input == "*"){
            result = arg1 * arg2;
        }else if(input == "/"){
            if(arg2 == 0.0f){
                printf("MATH ERROR: Division by zero is undefined\n");
                return 1;
            }
            result = arg1 / arg2;
        }else if(input = "^"){
            for(int i = 0; i < arg2; i++){
                if(i == 0){
                    ftemp = arg1;
                }else{
                    ftemp = ftemp * arg2;
                }
            }
            result = ftemp;
        }

        printf("= %f\n", result);

        vecf_push_back(&results, result);
        counter++;
    }

    vecf_free(&results);

    return 0;
}