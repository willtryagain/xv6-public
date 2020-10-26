void ps_func() {
    struct proc *p;
    for (p = ptable.proc; p < &ptable.proc[NPROC]; ++p) {
        //aquire print
        cprintf("%d\n", p -> state);
    }
}

int int main(int argc, char const *argv[]) {
    ps_func();
    return 0;
}
