defs.h : xv6에서 함수 원형과 커널 함수를 정의하는 헤더입니다. 레이어 간의 인터페이스 역할을 합니다.

forknexectest.c : user application으로 테스트용 파일입니다.

proc.c : 프로세스 관련 기능이 구현되어 있는 파일로, forknexec(const char *path, const char **args)가 정의되어 있습니다.

syscall.c : 매핑할 때 쓰는 파일입니다.

syscall.h : 매핑할 때 사용할 기호 상수가 정의된 헤더입니다.

sysproc.c : 프로세스 관련된 시스템 콜이 정의된 파일입니다.

user.h : forknexectest.c에서 참조하는 헤더 파일입니다. system call 관련 항목이 있습니다.

usys.S : 시스템콜 관련 매크로를 정의해줍니다.
