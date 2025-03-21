#include <iostream>


template<typename T, int N, int M>
class matrix
{
    private:
        T m_matrix[N][M];
        int rows = N;
        int columns = M;

    public:
        matrix()
        {
            for(int i=0; i<N; i++)
                for(int j =0; j<M; j++)
                    m_matrix[i][j] = 0;
        }

        matrix(T mass[N][M])
        {
            for(int i=0; i<N; i++)
                for(int j =0; j<M; j++)
                    m_matrix[i][j] = mass[i][j];
        }

        matrix(const matrix<T,N,M>& other)
        {
            rows = other.rows;
            columns = other.columns;

            for(int i=0; i<N; i++)
                for(int j =0; j<M; j++)
                    m_matrix[i][j] = other.m_matrix[i][j];
        }

        matrix<T,N,M>& operator=(matrix<T,N,M> other)
        {
            std::swap(rows,other.rows);
            std::swap(columns,other.columns);
            std::swap(m_matrix, other.m_matrix);
        }

        matrix<T,N,M>& operator+=(const matrix<T,N,M>& other)
        {
            for(int i=0; i<N; i++)
                for(int j =0; j<M; j++)
                    this->m_matrix[i][j] += other.m_matrix[i][j];
            return *this;
        }

        matrix<T,N,M> operator+(const matrix<T,N,M>& other)
        {
            matrix<T,N,M> result(*this);
            result += other;
            return result;
        }

        template<int L>
        matrix<T,N,L> operator*(const matrix<T,M,L>& other)
        {
            matrix<T,N,L> result;
            for(int i=0; i<N; i++)
                for(int j=0; j<L; j++)
                    for(int k=0; k<M; k++)
                        result.m_matrix[i][j] += this->m_matrix[i][k] * other.m_matrix[k][j];
            return result;
        }

        template<int L>
        matrix<T,N,L>& operator*=(const matrix<T,M,L>& other)
        {
            *this = *this * other;
            return *this;
        }

        T& getElement(int i, int j)
        {
            return m_matrix[i][j];
        }

        void setElement(int i, int j, T value)
        {
            m_matrix[i][j] = value;
        }

        matrix<T,N,M>& operator++()
        {
            for(int i=0; i<N; i++)
                for(int j =0; j<M; j++)
                    m_matrix[i][j] ++;
            return *this;
        }

        matrix<T, N, M>& operator++(int)
        {
            this->operator++();
            return *this;
        }

        T det()
        {
            std::cerr << "Recurtion" << std::endl;
            if(rows != columns)
            {
                std::cout << "Wrong dimention";
                throw std::exception("Wrong dimention");
            }

            if(rows == 1)
                return m_matrix[0][0];
            else if(rows == 2)
                return m_matrix[0][0] * m_matrix[1][1] - m_matrix[0][1] * m_matrix[1][0];
            else
            {
                T res = 0;
                for(int i=0; i<rows; i++)
                {
                    matrix<T,N,M> minor;
                    minor.rows = rows-1;
                    minor.columns = columns-1;
                    for(int n=0; n<minor.rows; n++)
                        for(int m=0; m<minor.columns; m++)
                        {
                            if(i>n)
                                minor.m_matrix[n][m] = this->m_matrix[n][m+1];
                            else
                                minor.m_matrix[n][m] = this->m_matrix[n+1][m+1];
                        }
                    
                    std::cerr << minor << std::endl;
                    res+= pow(-1,2+i)* minor.det()*m_matrix[i][0];
                    std::cerr << res << std::endl;
                }
                return res;
            }
        
        }

        template<typename T, int N, int M>
        friend std::ostream& operator<<(std::ostream& out, const matrix<T,N,M>& obj);

        template<typename T, int N, int M>
        friend std::istream& operator>>(std::istream& in, matrix<T,N,M>& obj);



};

template<typename T, int N, int M>
std::istream& operator>>(std::istream& in, matrix<T,N,M>& obj)
{
    for(int i=0; i<N; i++)
        for(int j =0; j<M; j++)
            in >> obj.m_matrix[i][j];
    
    return in;
}

template<typename T, int N, int M>
std::ostream& operator<<(std::ostream& out, const matrix<T,N,M>& obj)
{
    for(int i=0; i<N; i++)
    {
        for(int j =0; j<M; j++)
            out << obj.m_matrix[i][j] << ' ';
        out << '\n';
    }

    return out;
}





int main()
{
    /*
    matrix<int,2,2> test1;
    for(int i =0; i<2; i++)
        for(int j =0; j<2; j++)
            test1.setElement(i,j,i+j);
    
    matrix<int,2,2> test2 =test1;
    matrix<int,2,2> test3 = test1 * test2;
    test3++;
    */
    matrix<int,4,4> test;
    std::cin >> test;
    
    
    std::cout << test.det() << std::endl;

}