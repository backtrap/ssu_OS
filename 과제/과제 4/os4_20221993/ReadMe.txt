 * kalloc.c

unsigned int num_free_pages 선언
unsigned int pgrefcount[PHYSTOP >> PTXSHIFT] 선언

kinit1()에서 num_free_pages = 0으로 초기화
kfree()에서 num_free_pages++하고 dec_refcount() 호출
kalloc()에서 numl_free_pages--하고 refcount를 1로 설정

unsigend int get_refcount(unsigned int pa) 구현
void inc_refcount(unsigned int pa) 구현
void dec_refcount(unsigned int pa) 구현

freerange()에서 pgrefcount[]를 0으로 초기화

..~~~~..

 * vm.c

copyuvm()에서 Cow 구현하고 inc_refcount() 호출

pagefault() 구현

..~~~~..

 * trap.c

trap()에서 pagefault() 호출

..~~~~..

 * mmu.h

물리 메모리 이동을 위한 기호 상수 PGSHIFT 추가

..~~~~..

 * sysproc.c

sys_pagefault와 sys_getNumFreePages 시스템 콜의 코드 구현

..~~~~..

 * syscall.c

sys_pagefault와 sys_getNumFreePages 시스템 콜의 구문 분석 및 포인터 명시

..~~~~..

 * syscall.h

sys_pagefault와 sys_getNumFreePages 시스템 콜의 번호 매핑

..~~~~..

 * usys.S

sys_pagefault와 sys_getNumFreePages 시스템 콜을 시스템 콜 목록에 추가

..~~~~..

 * user.h

sys_pagefault와 sys_getNumFreePages 시스템 콜을 정의

..~~~~..

 * defs.h

sys_pagefault와 sys_getNumFreePages 시스템 콜이 다른 파일에서 보이도록 함

..~~~~..

 * test_1206.c

sys_pagefault와 sys_getNumFreePages 시스템 콜 구현을 확인하는 프로그램

..~~~~..

 * Makefie

xv6 실행 시 test_1206.c도 같이 컴파일
