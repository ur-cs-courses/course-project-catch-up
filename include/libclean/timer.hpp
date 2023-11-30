#ifndef LIBCLEAN_TIMER_HPP
#define LIBCLEAN_TIMERHPP

class Timer {
    private:
        int time;
    public:
        Timer();
        void addTime();
        int getTime();
};

#endif
