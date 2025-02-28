#include <iostream>


class mvector
{
    private:
        int mv_size;
        int mv_cap;
        int* mv_mass;

        void my_swap(mvector& a, mvector& b)
        {
            std::swap(a.mv_cap, b.mv_cap);
            std::swap(a.mv_mass, b.mv_mass);
            std::swap(a.mv_size, b.mv_size);
        }

    public:
        mvector(): mv_size(0), mv_cap(0), mv_mass(nullptr) {}

        mvector(int size): mv_size(size), mv_cap(size), mv_mass(new int[mv_size])
        {
            mv_mass = {0};
        }

        mvector(int size, int value): mv_size(size), mv_cap(size), mv_mass(new int[mv_size])
        {
            for(int i=0; i<mv_size; i++)
                mv_mass[i] = value;
        }

        mvector(const mvector& other)
        {
            mv_size = other.mv_size;
            mv_cap = other.mv_cap;
            mv_mass = new int[mv_size];
            std::copy(other.mv_mass, other.mv_mass + other.mv_size, mv_mass);
        }

        mvector& operator=(mvector other)
        {
            my_swap(*this, other);
            return *this;
        }

        ~mvector()
        {
            if(mv_mass!=nullptr)
                delete[] mv_mass;
        }

        void resize(int size)
        {
            if(size>mv_cap)
            {
                int* tmp = new int[size];
                std::copy(mv_mass, mv_mass + mv_size, tmp);
                mv_cap = size;
                mv_size = size;
                delete[] mv_mass;
                mv_mass = tmp;
            }
            else
                mv_size = size;
        }

        int size()
        {
            return mv_size;
        }

        void reserve(int cap)
        {
            if(cap < mv_size)
            {
                return;
            }

            int* tmp = new int[cap];
            std::copy(mv_mass, mv_mass + mv_size, tmp);
            mv_cap = cap;
            delete[] mv_mass;
            mv_mass = tmp;
        }

        int capacity()
        {
            return mv_cap;
        }

        void shrink_to_fit()
        {
            int* tmp = new int[mv_size];
            std::copy(mv_mass, mv_mass + mv_size, tmp);
            mv_cap = mv_size;
            delete[] mv_mass;
            mv_mass = tmp;
        }

        int& front()
        {
            return mv_mass[0];
        }

        int& back()
        {
            return mv_mass[mv_size-1];
        }

        bool empty()
        {
            return (mv_mass == nullptr);
        }

        void push_back(int value)
        {
            if(mv_size+1 <= mv_cap)
            {
                mv_mass[mv_size] = value;
                mv_size++;
            }

            mv_cap = mv_cap * 2 + 1;
            int* tmp = new int[mv_cap];
            std::copy(mv_mass, mv_mass + mv_size, tmp);
            tmp[mv_size] = value;
            mv_size++;
            delete[] mv_mass;
            mv_mass = tmp;
        }

        void insert(int index, int value)
        {
            if(mv_size + 1 <= mv_cap)
            {
                for(int i=mv_size;i>index;i--)
                {
                    mv_mass[i]=mv_mass[i-1];
                }
                mv_mass[index] = value;
                mv_size++;
            }
            else
            {
                mv_cap = mv_cap * 2 + 1;
                int* tmp = new int[mv_cap];
                std::copy(mv_mass, mv_mass + mv_size, tmp);

                for(int i=mv_size;i>index;i--)
                {
                    tmp[i]=tmp[i-1];
                }
                tmp[index] = value;
                mv_size++;

                delete[] mv_mass;
                mv_mass = tmp;
            }
        }

        int& operator[](int index)
        {
            return mv_mass[index];
        }

        void erase(int index)
        {
            int k=0;
            for(int i=index;i<mv_size-1;i++)
            {
                mv_mass[i]=mv_mass[i+1];
            }
            mv_size--;
        }
        
};

int main()
{
    mvector test(10,1);
    test[5] = 8;
    std::cout << test[5] << " " << test.size();
    test.erase(5);
    std::cout << test[5] << " " << test.size();

    return 0;
}
