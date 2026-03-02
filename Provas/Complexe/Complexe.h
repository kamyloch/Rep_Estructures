#ifndef COMPLEXE_H
#define COMPLEXE_H
template <class T>
class Complexe{
    private:
        T v_real;
        T v_imaginari;
    public:
        Complexe<T>(T r=0, T i=0);
        T real() const;
        T imaginari() const;
};
template <class T> Complexe<T>::Complexe(T r , T i) : v_real(r), v_imaginari(i){}
template <class T> T Complexe<T>::real() const { return v_real;}
template <class T> T Complexe<T>::imaginari() const { return v_imaginari; }
#endif