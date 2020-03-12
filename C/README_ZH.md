# 介绍

这个文件夹里的所有代码都是游鱼星敲的。

[英文版](./README.md)

## 代码介绍

`md5.h` 和 `md5.c` 实现了完整的MD5算法，虽然还没有优化过。

`test.h` 和 `test.c` 是过程中使用的测试文件，可以拿它测一下.

`utils.h` 和 `utils.c` 是中途遇到的工具函数,比如 `Hex2Int`

## 用法

### 1.直接搬代码

欢迎直接用我的代码，放在作业里就算了（或者你魔改一下，避免查重，谢谢）

### 2.使用静态库文件

```zsh
    make static #create the libary(it can be skiped)
    cd run
    vim main.c
    ...
    make        #create the binary executable file
    make run    #run your program
```

## others

欢迎交流和issue
