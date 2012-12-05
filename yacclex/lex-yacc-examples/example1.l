%{
#include <stdio.h>
%}

%%
[0-9]+     	printf("NUMBER");
^[ \t]+    	printf("whitespace from the beggining");
%%


