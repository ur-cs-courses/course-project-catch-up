#ifndef LIBCLEAN_TIMER_HPP
#define LIBCLEAN_TIMER_HPP

class Timer {
    private:
        static int time;
    public:
        Timer();
        void addTime();
        static int getTime();
};

#endif
