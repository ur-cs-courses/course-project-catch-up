#ifndef LIBCLEAN_ROOM_HPP
#define LIBCLEAN_ROOM_HPP

class Room{
    public:
        std::string name;
        float width;
        float length;
        bool sweepable;
        bool moppable;
        bool scrubbable;

        Room(std::string name, float width, float length, bool sweepable, bool moppable, bool scrubbable);
        float percentSwept;
        float percentMopped;
        float percentScrubbed;

        float getSize();

        void setPercentSwept(float percent);
        void setPercentMopped(float percent);
        void setPercentScrubbed(float percent);

        void randomlyDirty();
};

#endif