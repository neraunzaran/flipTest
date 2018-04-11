/*
    flipTest is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    flipTest is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with flipTest.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef MODELS_HPP
#define MODELS_HPP
#define STAN__SERVICES__COMMAND_HPP
#include <rstan/rstaninc.hpp>
// Code generated by Stan version 2.17.0

#include <stan/model/model_header.hpp>

namespace model_binomialproportions_namespace {

using std::istream;
using std::string;
using std::stringstream;
using std::vector;
using stan::io::dump;
using stan::math::lgamma;
using stan::model::prob_grad;
using namespace stan::math;

typedef Eigen::Matrix<double,Eigen::Dynamic,1> vector_d;
typedef Eigen::Matrix<double,1,Eigen::Dynamic> row_vector_d;
typedef Eigen::Matrix<double,Eigen::Dynamic,Eigen::Dynamic> matrix_d;

static int current_statement_begin__;

stan::io::program_reader prog_reader__() {
    stan::io::program_reader reader;
    reader.add_event(0, 0, "start", "model_binomialproportions");
    reader.add_event(26, 26, "end", "model_binomialproportions");
    return reader;
}

#include <meta_header.hpp>
 class model_binomialproportions : public prob_grad {
private:
    int groups;
    vector<int> trials;
    vector<int> successes;
public:
    model_binomialproportions(stan::io::var_context& context__,
        std::ostream* pstream__ = 0)
        : prob_grad(0) {
        ctor_body(context__, 0, pstream__);
    }

    model_binomialproportions(stan::io::var_context& context__,
        unsigned int random_seed__,
        std::ostream* pstream__ = 0)
        : prob_grad(0) {
        ctor_body(context__, random_seed__, pstream__);
    }

    void ctor_body(stan::io::var_context& context__,
                   unsigned int random_seed__,
                   std::ostream* pstream__) {
        boost::ecuyer1988 base_rng__ =
          stan::services::util::create_rng(random_seed__, 0);
        (void) base_rng__;  // suppress unused var warning

        current_statement_begin__ = -1;

        static const char* function__ = "model_binomialproportions_namespace::model_binomialproportions";
        (void) function__;  // dummy to suppress unused var warning
        size_t pos__;
        (void) pos__;  // dummy to suppress unused var warning
        std::vector<int> vals_i__;
        std::vector<double> vals_r__;
        double DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning

        // initialize member variables
        try {
            current_statement_begin__ = 3;
            context__.validate_dims("data initialization", "groups", "int", context__.to_vec());
            groups = int(0);
            vals_i__ = context__.vals_i("groups");
            pos__ = 0;
            groups = vals_i__[pos__++];
            current_statement_begin__ = 5;
            validate_non_negative_index("trials", "groups", groups);
            context__.validate_dims("data initialization", "trials", "int", context__.to_vec(groups));
            validate_non_negative_index("trials", "groups", groups);
            trials = std::vector<int>(groups,int(0));
            vals_i__ = context__.vals_i("trials");
            pos__ = 0;
            size_t trials_limit_0__ = groups;
            for (size_t i_0__ = 0; i_0__ < trials_limit_0__; ++i_0__) {
                trials[i_0__] = vals_i__[pos__++];
            }
            current_statement_begin__ = 7;
            validate_non_negative_index("successes", "groups", groups);
            context__.validate_dims("data initialization", "successes", "int", context__.to_vec(groups));
            validate_non_negative_index("successes", "groups", groups);
            successes = std::vector<int>(groups,int(0));
            vals_i__ = context__.vals_i("successes");
            pos__ = 0;
            size_t successes_limit_0__ = groups;
            for (size_t i_0__ = 0; i_0__ < successes_limit_0__; ++i_0__) {
                successes[i_0__] = vals_i__[pos__++];
            }

            // validate, data variables
            current_statement_begin__ = 3;
            check_greater_or_equal(function__,"groups",groups,1);
            current_statement_begin__ = 5;
            current_statement_begin__ = 7;
            // initialize data variables


            // validate transformed data

            // validate, set parameter ranges
            num_params_r__ = 0U;
            param_ranges_i__.clear();
            current_statement_begin__ = 11;
            validate_non_negative_index("rates", "groups", groups);
            num_params_r__ += groups;
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }
    }

    ~model_binomialproportions() { }


    void transform_inits(const stan::io::var_context& context__,
                         std::vector<int>& params_i__,
                         std::vector<double>& params_r__,
                         std::ostream* pstream__) const {
        stan::io::writer<double> writer__(params_r__,params_i__);
        size_t pos__;
        (void) pos__; // dummy call to supress warning
        std::vector<double> vals_r__;
        std::vector<int> vals_i__;

        if (!(context__.contains_r("rates")))
            throw std::runtime_error("variable rates missing");
        vals_r__ = context__.vals_r("rates");
        pos__ = 0U;
        validate_non_negative_index("rates", "groups", groups);
        context__.validate_dims("initialization", "rates", "double", context__.to_vec(groups));
        std::vector<double> rates(groups,double(0));
        for (int i0__ = 0U; i0__ < groups; ++i0__)
            rates[i0__] = vals_r__[pos__++];
        for (int i0__ = 0U; i0__ < groups; ++i0__)
            try {
            writer__.scalar_lub_unconstrain(0,1,rates[i0__]);
        } catch (const std::exception& e) { 
            throw std::runtime_error(std::string("Error transforming variable rates: ") + e.what());
        }

        params_r__ = writer__.data_r();
        params_i__ = writer__.data_i();
    }

    void transform_inits(const stan::io::var_context& context,
                         Eigen::Matrix<double,Eigen::Dynamic,1>& params_r,
                         std::ostream* pstream__) const {
      std::vector<double> params_r_vec;
      std::vector<int> params_i_vec;
      transform_inits(context, params_i_vec, params_r_vec, pstream__);
      params_r.resize(params_r_vec.size());
      for (int i = 0; i < params_r.size(); ++i)
        params_r(i) = params_r_vec[i];
    }


    template <bool propto__, bool jacobian__, typename T__>
    T__ log_prob(vector<T__>& params_r__,
                 vector<int>& params_i__,
                 std::ostream* pstream__ = 0) const {

        T__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning

        T__ lp__(0.0);
        stan::math::accumulator<T__> lp_accum__;

        try {
            // model parameters
            stan::io::reader<T__> in__(params_r__,params_i__);

            vector<T__> rates;
            size_t dim_rates_0__ = groups;
            rates.reserve(dim_rates_0__);
            for (size_t k_0__ = 0; k_0__ < dim_rates_0__; ++k_0__) {
                if (jacobian__)
                    rates.push_back(in__.scalar_lub_constrain(0,1,lp__));
                else
                    rates.push_back(in__.scalar_lub_constrain(0,1));
            }


            // transformed parameters



            // validate transformed parameters

            const char* function__ = "validate transformed params";
            (void) function__;  // dummy to suppress unused var warning

            // model body

            current_statement_begin__ = 15;
            lp_accum__.add(uniform_log<propto__>(rates, 0, 1));
            current_statement_begin__ = 16;
            for (int g = 1; g <= groups; ++g) {
                current_statement_begin__ = 17;
                lp_accum__.add(binomial_log<propto__>(get_base1(successes,g,"successes",1), get_base1(trials,g,"trials",1), get_base1(rates,g,"rates",1)));
            }

        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }

        lp_accum__.add(lp__);
        return lp_accum__.sum();

    } // log_prob()

    template <bool propto, bool jacobian, typename T_>
    T_ log_prob(Eigen::Matrix<T_,Eigen::Dynamic,1>& params_r,
               std::ostream* pstream = 0) const {
      std::vector<T_> vec_params_r;
      vec_params_r.reserve(params_r.size());
      for (int i = 0; i < params_r.size(); ++i)
        vec_params_r.push_back(params_r(i));
      std::vector<int> vec_params_i;
      return log_prob<propto,jacobian,T_>(vec_params_r, vec_params_i, pstream);
    }


    void get_param_names(std::vector<std::string>& names__) const {
        names__.resize(0);
        names__.push_back("rates");
        names__.push_back("mx");
        names__.push_back("preferred");
    }


    void get_dims(std::vector<std::vector<size_t> >& dimss__) const {
        dimss__.resize(0);
        std::vector<size_t> dims__;
        dims__.resize(0);
        dims__.push_back(groups);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dims__.push_back(groups);
        dimss__.push_back(dims__);
    }

    template <typename RNG>
    void write_array(RNG& base_rng__,
                     std::vector<double>& params_r__,
                     std::vector<int>& params_i__,
                     std::vector<double>& vars__,
                     bool include_tparams__ = true,
                     bool include_gqs__ = true,
                     std::ostream* pstream__ = 0) const {
        vars__.resize(0);
        stan::io::reader<double> in__(params_r__,params_i__);
        static const char* function__ = "model_binomialproportions_namespace::write_array";
        (void) function__;  // dummy to suppress unused var warning
        // read-transform, write parameters
        vector<double> rates;
        size_t dim_rates_0__ = groups;
        for (size_t k_0__ = 0; k_0__ < dim_rates_0__; ++k_0__) {
            rates.push_back(in__.scalar_lub_constrain(0,1));
        }
            for (int k_0__ = 0; k_0__ < groups; ++k_0__) {
            vars__.push_back(rates[k_0__]);
            }

        if (!include_tparams__) return;
        // declare and define transformed parameters
        double lp__ = 0.0;
        (void) lp__;  // dummy to suppress unused var warning
        stan::math::accumulator<double> lp_accum__;

        double DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning

        try {



            // validate transformed parameters

            // write transformed parameters

            if (!include_gqs__) return;
            // declare and define generated quantities
            current_statement_begin__ = 21;
            double mx(0.0);
            (void) mx;  // dummy to suppress unused var warning

            stan::math::initialize(mx, std::numeric_limits<double>::quiet_NaN());
            stan::math::fill(mx,DUMMY_VAR__);
            current_statement_begin__ = 22;
            validate_non_negative_index("preferred", "groups", groups);
            vector<double> preferred(groups, 0.0);
            stan::math::initialize(preferred, std::numeric_limits<double>::quiet_NaN());
            stan::math::fill(preferred,DUMMY_VAR__);


            current_statement_begin__ = 23;
            stan::math::assign(mx, max(rates));
            current_statement_begin__ = 24;
            for (int g = 1; g <= groups; ++g) {
                current_statement_begin__ = 25;
                stan::math::assign(get_base1_lhs(preferred,g,"preferred",1), (logical_eq(get_base1(rates,g,"rates",1),mx) ? stan::math::promote_scalar<double>(1.0) : stan::math::promote_scalar<double>(0.0) ));
            }

            // validate generated quantities
            current_statement_begin__ = 21;
            current_statement_begin__ = 22;

            // write generated quantities
        vars__.push_back(mx);
            for (int k_0__ = 0; k_0__ < groups; ++k_0__) {
            vars__.push_back(preferred[k_0__]);
            }

        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }
    }

    template <typename RNG>
    void write_array(RNG& base_rng,
                     Eigen::Matrix<double,Eigen::Dynamic,1>& params_r,
                     Eigen::Matrix<double,Eigen::Dynamic,1>& vars,
                     bool include_tparams = true,
                     bool include_gqs = true,
                     std::ostream* pstream = 0) const {
      std::vector<double> params_r_vec(params_r.size());
      for (int i = 0; i < params_r.size(); ++i)
        params_r_vec[i] = params_r(i);
      std::vector<double> vars_vec;
      std::vector<int> params_i_vec;
      write_array(base_rng,params_r_vec,params_i_vec,vars_vec,include_tparams,include_gqs,pstream);
      vars.resize(vars_vec.size());
      for (int i = 0; i < vars.size(); ++i)
        vars(i) = vars_vec[i];
    }

    static std::string model_name() {
        return "model_binomialproportions";
    }


    void constrained_param_names(std::vector<std::string>& param_names__,
                                 bool include_tparams__ = true,
                                 bool include_gqs__ = true) const {
        std::stringstream param_name_stream__;
        for (int k_0__ = 1; k_0__ <= groups; ++k_0__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "rates" << '.' << k_0__;
            param_names__.push_back(param_name_stream__.str());
        }

        if (!include_gqs__ && !include_tparams__) return;

        if (!include_gqs__) return;
        param_name_stream__.str(std::string());
        param_name_stream__ << "mx";
        param_names__.push_back(param_name_stream__.str());
        for (int k_0__ = 1; k_0__ <= groups; ++k_0__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "preferred" << '.' << k_0__;
            param_names__.push_back(param_name_stream__.str());
        }
    }


    void unconstrained_param_names(std::vector<std::string>& param_names__,
                                   bool include_tparams__ = true,
                                   bool include_gqs__ = true) const {
        std::stringstream param_name_stream__;
        for (int k_0__ = 1; k_0__ <= groups; ++k_0__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "rates" << '.' << k_0__;
            param_names__.push_back(param_name_stream__.str());
        }

        if (!include_gqs__ && !include_tparams__) return;

        if (!include_gqs__) return;
        param_name_stream__.str(std::string());
        param_name_stream__ << "mx";
        param_names__.push_back(param_name_stream__.str());
        for (int k_0__ = 1; k_0__ <= groups; ++k_0__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "preferred" << '.' << k_0__;
            param_names__.push_back(param_name_stream__.str());
        }
    }

}; // model

}

typedef model_binomialproportions_namespace::model_binomialproportions stan_model;


#endif
