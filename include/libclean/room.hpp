#ifndef LIBCLEAN_ROOM_HPP
#define LIBCLEAN_ROOM_HPP

class Room{
    private:
        string Name;
        float width;
        float length;
        bool sweepable;
        bool moppable;
        bool scrubbable;

    public:
        float percentSwept;
        float percentMopped;
        float percentScrubbed;

        float getSize();

        float setPercentSwept(float percent);
        float setPercentMopped(float percent);
        float setPercentScrubbed(float percent);

        void randomlyDirty();
}