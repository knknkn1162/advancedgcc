+ try `make` and `make NOSTDLIB=1`. If you build with `make` only, `syscall` function in assembly is like this:

```sh
0000000000401060 <syscall>:
  401060:	48 89 f8             	mov    %rdi,%rax
  401063:	48 89 f7             	mov    %rsi,%rdi
  401066:	48 89 d6             	mov    %rdx,%rsi
  401069:	48 89 ca             	mov    %rcx,%rdx
  40106c:	4d 89 c2             	mov    %r8,%r10
  40106f:	4d 89 c8             	mov    %r9,%r8
  401072:	4c 8b 4c 24 08       	mov    0x8(%rsp),%r9
  401077:	0f 05                	syscall
  401079:	48 3d 01 f0 ff ff    	cmp    $0xfffffffffffff001,%rax
  40107f:	73 01                	jae    401082 <syscall+0x22>
  401081:	c3                   	retq
  401082:	48 c7 c1 fc ff ff ff 	mov    $0xfffffffffffffffc,%rcx
  401089:	f7 d8                	neg    %eax
  40108b:	64 89 01             	mov    %eax,%fs:(%rcx)
  40108e:	48 83 c8 ff          	or     $0xffffffffffffffff,%rax
  401092:	c3                   	retq
```
