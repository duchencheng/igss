#include "CenterLinePoint.h"

CenterLinePoint::CenterLinePoint()
{
    pos_x=0.0;
    pos_y=0.0;
    pos_z=0.0;
    radius=0.0;

}

void  CenterLinePoint::set_abscissa(double pos_x){
    this->pos_x=pos_x;
}

void  CenterLinePoint::set_vertical(double pos_y){
    this->pos_y=pos_y;
}

void  CenterLinePoint::set_sagittal(double pos_z){
    this->pos_z;
}

void  CenterLinePoint::set_radius_size(double radius){
    this->radius=radius;
}

double CenterLinePoint::get_abscissa(){
    return this->pos_x;
}

double CenterLinePoint::get_vertical(){
    return this->pos_y;
}

double CenterLinePoint::get_sagittal(){
    return this->pos_z;
}

double CenterLinePoint::get_radius_size(){
    return this->radius;
}
