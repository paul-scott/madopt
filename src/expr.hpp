/*
 * Copyright 2014 National ICT Australia Limited (NICTA)
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *     http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef MADOPT_EXPR_H
#define MADOPT_EXPR_H

#include "operator.hpp"
#include <deque>
#include <set>

namespace MadOpt {

//! expression class
class Expr{
    public:
        Expr(){};

        //! move constructor
        Expr(Expr&& a)=default;

        //! copy constructor
        Expr(const Expr& a)=default;

        //! equality copy constructor
        Expr& operator=(const Expr& a)=default;

        //! \brief construct constant expression,
        Expr(double constant);

        //! \brief construct constant expression,
        Expr(int constant);

        Expr(const Expr& a, const double& b);

        Expr(const Expr& a, int op);

        Expr(const Expr& a, OPType op);

        //! \sa
        Expr& operator+();

        //! \sa
        Expr& operator+=(const double& a);

        //! \sa
        Expr& operator*=(const double& a);

        //! \sa
        Expr operator+(const Expr& b)const ;

        //! \sa
        Expr operator*(const Expr& b)const ;

        //! \sa
        Expr& operator+=(const Expr& a);

        //! \sa
        Expr& operator+=(const Expr&& a) ;                                

        //! \sa
        Expr& operator*=(const Expr& a);

        //! \sa
        Expr& operator*=(const Expr&& a);

        friend Expr operator+(const Expr& a, const double& b);
        friend Expr operator+(const double& a, const Expr& b);
        friend Expr operator*(const Expr& a, const double& b);
        friend Expr operator*(const double& a, const Expr& b);
        friend Expr operator-(const Expr& a);
        friend Expr operator-(const Expr& a, const Expr& b);
        friend Expr operator-(const Expr& a, const double& b);
        friend Expr pow(const Expr& a, const double& b);
        friend Expr operator/(const Expr& a, const Expr& b);
        friend Expr sin(const Expr& a);
        friend Expr cos(const Expr& a);
        friend Expr tan(const Expr& a);

        string opsToString()const; 

        Expr& mulEqual(const Expr& a); 

        Expr& plusEqual(const Expr& a); 

        bool isZero()const; 

        bool isOne()const; 

        set<InnerVar*> getInnerVariables()const; 

        //! print the expression
        string toString()const; 

        const OPType& getType()const; 

        //! return true if the expression is constant
        bool isConstant()const; 

        const Operator& front()const; 

        Operator& front(); 

        double getConstantValue()const; 

        const deque<Operator>::const_iterator begin()const; 

        const deque<Operator>::const_iterator end()const; 

        deque<Operator>::iterator begin(); 

        deque<Operator>::iterator end();

        Idx size()const; 

        const deque<Operator>& getOps()const ; 

        //! evaluate the expression using the values from the solution
        double x()const; 

    protected:

        deque<Operator> ops;

        string toString(deque<Operator>::const_iterator& iter)const; 

        string toStringEnclosed(deque<Operator>::const_iterator& iter)const;

        string getContent(deque<Operator>::const_iterator& iter,
                string delimeter)const;

        inline Expr& addOrMulOp(bool x, bool y, const Expr& a, OPType type, bool op);

        inline Expr& addOrMulOp(bool x, bool y, Expr&& a, OPType type, bool op);

        inline int inner(const Expr& a, OPType& type, bool& op);

        double x(deque<Operator>::const_iterator& iter)const;
};

//! \sa
Expr operator+(const Expr& a, const double& b);
//! \sa
Expr operator+(const double& a, const Expr& b);
//! \sa
Expr operator*(const Expr& a, const double& b);
//! \sa
Expr operator*(const double& a, const Expr& b);
//! \sa
Expr operator-(const Expr& a);
//! \sa
Expr operator-(const Expr& a, const Expr& b);
//! \sa
Expr operator-(const Expr& a, const double& b);
//! \sa
Expr pow(const Expr& a, const double& b);
//! \sa
Expr operator/(const Expr& a, const Expr& b);
//! \sa
Expr sin(const Expr& a);
//! \sa
Expr cos(const Expr& a);
//! \sa
std::ostream &operator<<(std::ostream &os, const Expr &a);

} /* madopt */ 

#endif
/* ex: set tabstop=4 shiftwidth=4 expandtab: */
