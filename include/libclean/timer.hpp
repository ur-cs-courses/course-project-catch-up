#ifndef LIBCLEAN_TIMER_HPP
#define LIBCLEAN_TIMER_HPP

class Timer {
    private:
        int time;

    public:
        Timer();
        void addTime();
        int getTime();
};

#endif
