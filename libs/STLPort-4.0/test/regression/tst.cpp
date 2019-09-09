
namespace aaa
{
    template <class One, class Two>
    class A 
    {
    public:
        A() 
            {
            }
        
    }
    ;
}
namespace bbb 
{

    template <class B>
class A_proxy : public B
{
public:
//    using aaa::A;
//    template class aaa::A;
    typedef B the_a;
};
}


namespace bbb
{

    template <class One, class Two>
    class A : public A_proxy< aaa::A<One, Two> >::the_a
    
    {
    public:
        A() 
            {
            }
        
    }
    ;
}

int
main()
{
    using namespace bbb;
    A<int,int> a;
    
}
