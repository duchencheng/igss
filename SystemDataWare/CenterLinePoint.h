#ifndef CENTERLINEPOINT_H
#define CENTERLINEPOINT_H


class CenterLinePoint
{
public:
    CenterLinePoint();

private:
    double pos_x;
    double pos_y;
    double pos_z;
    double radius;

public:
    void  set_abscissa(double pos_x);
    void  set_vertical(double pos_y);
    void  set_sagittal(double pos_z);
    void  set_radius_size(double radius);

    double get_abscissa();
    double get_vertical();
    double get_sagittal();
    double get_radius_size();

};

#endif // CENTERLINEPOINT_H
