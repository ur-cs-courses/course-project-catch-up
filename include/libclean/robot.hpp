#ifndef LIBCLEAN_ROBOT_HPP
#define LIBCLEAN_ROBOT_HPP

class Robot{
    private:
        string Name;
        float batery;
        Size size;
        string location;

    public:
        void move();
        bool ifBusy();
        float getBattery();
        Size getSize();
        void charge();
        void setName();
        bool hasFailed();
        bool isRoomClean();
};
#endif;