헤더 파일로는 types.h, stat.h, user.h를 사용했습니다. prinf.c, prinf.d에서 확인한 헤더 파일입니다.

함수의 원형은 prinf(정수, 문자열, ...)입니다. 이 역시 prinf.c에서 확인했습니다.

Makefile은 xv6에서 ls를 통해 확인한 명령어들이 있는 부분을 찾아 제 파일을 추가시켰습니다. 즉, UPROGS와 EXTRA 부분의 마지막에 helloword를 해당 부분의 양식에 맞춰 수정했습니다.