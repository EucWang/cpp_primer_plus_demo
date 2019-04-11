#include <iostream>
using namespace std;

struct box{
    char maker[40];
    float height;
    float width;
    float length;
    float volume;
};

void show_box(box b);

void auto_set_box_volume(box * b);

int main52() {
   
    // cout.setf(ios_base::fixed, ios_base::floatfield);
    cout<<endl;

    box b = {
        "MaxBox", 10.0, 10.0, 10.0, 10
    };
    show_box(b);
    auto_set_box_volume(&b);
    cout << "After calculate volume : info is : \n";
    show_box(b);
    
    cout<<endl;
    return 0;
}

void show_box(box b) {
    cout << "Box info [ #maker: " << b.maker << ", #height:"
        << b.height << ", #width:" << b.width << ", #length:" 
        << b.length << ", #volume:" << b.volume << "]\n";
}

void auto_set_box_volume(box * b){
    b->volume = b->height * b->width * b->length;
}
