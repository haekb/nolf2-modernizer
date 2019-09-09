#ifndef __LTRECT_H__
#define __LTRECT_H__


class LTRect {
public:

/*!
\param l x position of left side
\param t y position of top side
\param r x position of right side
\param b y position of bottom side

Used for: Misc.
*/
    LTRect(int l=0, int t=0, int r=0, int b=0) : left(l), top(t), right(r), bottom(b) {}

/*!
\param inLeft x position of left side
\param inTop y position of top side
\param inRight x position of right side
\param inBottom y position of bottom side

Initialize the values.

Used for:   2D Rendering.
*/
    void Init(int inLeft, int inTop, int inRight, int inBottom) {
        left = inLeft;
        top = inTop;
        right = inRight;
        bottom = inBottom;
    }

    int left, top, right, bottom;
};

#endif  //! __LTRECT_H__













