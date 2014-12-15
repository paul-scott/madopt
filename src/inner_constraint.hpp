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
#ifndef MADOPT_INNER_CONSTRAINT_H
#define MADOPT_INNER_CONSTRAINT_H

#include "common.hpp"

namespace MadOpt {

class Solution;
class ADStack;

class InnerConstraint{
    public:
        virtual ~InnerConstraint();

        virtual double eval(const double* x);

        virtual void eval_jac(const double* x, double* values);

        virtual void eval_h(const double* x, double* values, const double& lambda);

        virtual double lb()=0;
        virtual void lb(double v);

        virtual double ub()=0;
        virtual void ub(double v);

        virtual Idx getNNZ_Jac();

        virtual vector<Idx> getJacEntries()=0;

        virtual void getNZ_Jac(int* jCol);

        virtual void setStack(ADStack* stack);

        virtual vector<PII> getHessEntries();

        virtual void init(HessPosMap& hess_pos_map);

        virtual void setEvals(const double* x)=0;

        void setPos(Idx epos) ;
        Idx getPos()const ;

        void setSolutionClass(Solution* sol);

        double lam()const ;;

        const double& getG()const ;

        const vector<double>& getJac()const ;

        const vector<double>& getHess()const ;

        const vector<Idx>& getHessMap()const;

        virtual const string toString()const=0;

    protected:
        double g;
        vector<double> jac;
        vector<double> hess;
        vector<Idx> hess_map;
        Idx pos=0;
        Solution* sol;
};
}
#endif
