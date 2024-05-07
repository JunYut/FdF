Size: 112
ptr: 0x7faa1ac59d10

Size: 128
ptr: 0x7faa1ac5a930

Size: 480
ptr: 0x7faa1ac5e0f0

Size: 480
ptr: 0x7faa1ac5e2d0

Start addr: 0x7faa1e000000
Image size: 1920000
End addr: 0x7FAA1F920000

Start addr: 0x7faa1e000000
Offset size: 1923200
End addr: 0x7faa1e1d5880

Size: 1923200
ptr: 0x7faa1e1d5880

Size: 480
ptr: 0x7faa1ac99340

-------------------------------------------------------------------------------

Process 12415 launched: '/Users/tjun-yu/Documents/42_cursus/local/FdF/macOS/main' (x86_64)
Size: 112
ptr: 0x100529a70

Size: 128
ptr: 0x100529af0

Size: 480
ptr: 0x100529dd0

Size: 480
ptr: 0x100529fb0

Start addr: 0x10816b000
Memory size: 1923200
End addr: 0x108340880

Size: 1923200
Process 12415 stopped
* thread #1, queue = 'com.apple.main-thread', stop reason = EXC_BAD_ACCESS (code=2, address=0x108340000)
    frame #0: 0x0000000100007844 main`ft_memset + 84
main`ft_memset:
->  0x100007844 <+84>: movb   %al, (%rcx,%rdx)
    0x100007847 <+87>: jmp    0x100007824               ; <+52>
    0x10000784c <+92>: movq   -0x20(%rbp), %rax
    0x100007850 <+96>: movslq -0x24(%rbp), %rcx
Target 0: (main) stopped.

-------------------------------------------------------------------------------

Process 13576 launched: '/Users/tjun-yu/Documents/42_cursus/local/FdF/macOS/main' (x86_64)
Size: 112
ptr: 0x100528d50

Size: 128
ptr: 0x10053b0a0

Size: 480
ptr: 0x10053eb00

Size: 480
ptr: 0x10053ece0

Start addr: 0x10819e000
Memory size: 1923200
End addr: 0x108373880

Size: 1923200
Process 13576 stopped
* thread #1, queue = 'com.apple.main-thread', stop reason = EXC_BAD_ACCESS (code=2, address=0x108373000)
    frame #0: 0x0000000100007844 main`ft_memset + 84
main`ft_memset:
->  0x100007844 <+84>: movb   %al, (%rcx,%rdx)
    0x100007847 <+87>: jmp    0x100007824               ; <+52>
    0x10000784c <+92>: movq   -0x20(%rbp), %rax
    0x100007850 <+96>: movslq -0x24(%rbp), %rcx
Target 0: (main) stopped.

-------------------------------------------------------------------------------

Process 14051 launched: '/Users/tjun-yu/Documents/42_cursus/local/FdF/macOS/main' (x86_64)
Size: 112
ptr: 0x100332550

Size: 128
ptr: 0x1003325d0

Size: 480
ptr: 0x100332890

Size: 480
ptr: 0x100332a70

Start addr: 0x1080a2000
Memory size: 1923200
End addr: 0x108277880

Size: 1923200
Process 14051 stopped
* thread #1, queue = 'com.apple.main-thread', stop reason = EXC_BAD_ACCESS (code=2, address=0x108277000)
    frame #0: 0x0000000100007844 main`ft_memset + 84
main`ft_memset:
->  0x100007844 <+84>: movb   %al, (%rcx,%rdx)
    0x100007847 <+87>: jmp    0x100007824               ; <+52>
    0x10000784c <+92>: movq   -0x20(%rbp), %rax
    0x100007850 <+96>: movslq -0x24(%rbp), %rcx
Target 0: (main) stopped.