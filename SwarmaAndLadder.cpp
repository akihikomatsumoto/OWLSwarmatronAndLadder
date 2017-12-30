#include "SwarmaAndLadder.h"

namespace SwarmaAndLadder {

/*******************************************************************************************************************
Cycling '74 License for Max-Generated Code for Export
Copyright (c) 2016 Cycling '74
The code that Max generates automatically and that end users are capable of exporting and using, and any
  associated documentation files (the “Software”) is a work of authorship for which Cycling '74 is the author
  and owner for copyright purposes.  A license is hereby granted, free of charge, to any person obtaining a
  copy of the Software (“Licensee”) to use, copy, modify, merge, publish, and distribute copies of the Software,
  and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
The Software is licensed to Licensee only for non-commercial use. Users who wish to make commercial use of the
  Software must contact the copyright owner to determine if a license for commercial use is available, and the
  terms and conditions for same, which may include fees or royalties. For commercial use, please send inquiries
  to licensing (at) cycling74.com.  The determination of whether a use is commercial use or non-commercial use is based
  upon the use, not the user. The Software may be used by individuals, institutions, governments, corporations, or
  other business whether for-profit or non-profit so long as the use itself is not a commercialization of the
  materials or a use that generates or is intended to generate income, revenue, sales or profit.
The above copyright notice and this license shall be included in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO
  THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. IN NO EVENT SHALL
  THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
  CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
  DEALINGS IN THE SOFTWARE.
*******************************************************************************************************************/

// global noise generator
Noise noise;
static const int GENLIB_LOOPCOUNT_BAIL = 100000;


// The State struct contains all the state and procedures for the gendsp kernel
typedef struct State {
	CommonState __commonstate;
	Phasor __m_phasor_25;
	Phasor __m_phasor_16;
	Phasor __m_phasor_17;
	Phasor __m_phasor_15;
	Phasor __m_phasor_14;
	Phasor __m_phasor_13;
	Phasor __m_phasor_18;
	Phasor __m_phasor_20;
	Phasor __m_phasor_23;
	Phasor __m_phasor_19;
	Phasor __m_phasor_22;
	Phasor __m_phasor_21;
	Phasor __m_phasor_24;
	int __exception;
	int vectorsize;
	t_sample m_B_2;
	t_sample samples_to_seconds;
	t_sample m_C_3;
	t_sample m_D_1;
	t_sample samplerate;
	t_sample m_z_11;
	t_sample m_A_4;
	t_sample m_y_7;
	t_sample m_z_10;
	t_sample m_mf_6;
	t_sample m_z_9;
	t_sample m_z_8;
	t_sample m_z_12;
	// re-initialize all member variables;
	inline void reset(t_param __sr, int __vs) {
		__exception = 0;
		vectorsize = __vs;
		samplerate = __sr;
		m_D_1 = ((int)0);
		m_B_2 = ((int)0);
		m_C_3 = ((int)0);
		m_A_4 = ((int)0);
		m_mf_6 = ((int)0);
		m_y_7 = ((int)0);
		m_z_8 = ((int)0);
		m_z_9 = ((int)0);
		m_z_10 = ((int)0);
		m_z_11 = ((int)0);
		m_z_12 = ((int)0);
		samples_to_seconds = (1 / samplerate);
		__m_phasor_13.reset(0);
		__m_phasor_14.reset(0);
		__m_phasor_15.reset(0);
		__m_phasor_16.reset(0);
		__m_phasor_17.reset(0);
		__m_phasor_18.reset(0);
		__m_phasor_19.reset(0);
		__m_phasor_20.reset(0);
		__m_phasor_21.reset(0);
		__m_phasor_22.reset(0);
		__m_phasor_23.reset(0);
		__m_phasor_24.reset(0);
		__m_phasor_25.reset(0);
		genlib_reset_complete(this);
		
	};
	// the signal processing routine;
	inline int perform(t_sample ** __ins, t_sample ** __outs, int __n) {
		vectorsize = __n;
		const t_sample * __in1 = __ins[0];
		t_sample * __out1 = __outs[0];
		t_sample * __out2 = __outs[1];
		if (__exception) {
			return __exception;
			
		} else if (( (__in1 == 0) || (__out1 == 0) || (__out2 == 0) )) {
			__exception = GENLIB_ERR_NULL_BUFFER;
			return __exception;
			
		};
		t_sample pow_17 = safepow(m_C_3, ((int)2));
		t_sample sub_78 = (pow_17 - ((int)0));
		t_sample scale_75 = ((safepow((sub_78 * ((t_sample)1)), ((int)1)) * ((int)19970)) + ((int)30));
		t_sample max_5 = (samplerate * ((t_sample)0.25));
		t_sample cf = ((scale_75 <= ((int)20)) ? ((int)20) : ((scale_75 >= max_5) ? max_5 : scale_75));
		int res = ((((int)0) <= ((int)0)) ? ((int)0) : ((((int)0) >= ((int)1)) ? ((int)1) : ((int)0)));
		t_sample pow_19 = safepow(m_A_4, ((int)2));
		t_sample sub_82 = (pow_19 - ((int)0));
		t_sample scale_79 = ((safepow((sub_82 * ((t_sample)1)), ((int)1)) * ((int)2980)) + ((int)20));
		samples_to_seconds = (1 / samplerate);
		t_sample pow_18 = safepow(m_B_2, ((int)2));
		t_sample sub_90 = (pow_18 - ((int)0));
		t_sample scale_87 = ((safepow((sub_90 * ((t_sample)1)), ((int)1)) * ((t_sample)0.3)) + ((int)0));
		t_sample sub_24 = (((int)1) - scale_87);
		t_sample mul_61 = (pow_19 * sub_24);
		t_sample sub_94 = (mul_61 - ((int)0));
		t_sample scale_91 = ((safepow((sub_94 * ((t_sample)1)), ((int)1)) * ((int)2980)) + ((int)20));
		t_sample mul_59 = (mul_61 * sub_24);
		t_sample sub_102 = (mul_59 - ((int)0));
		t_sample scale_99 = ((safepow((sub_102 * ((t_sample)1)), ((int)1)) * ((int)2980)) + ((int)20));
		t_sample mul_56 = (mul_59 * sub_24);
		t_sample sub_110 = (mul_56 - ((int)0));
		t_sample scale_107 = ((safepow((sub_110 * ((t_sample)1)), ((int)1)) * ((int)2980)) + ((int)20));
		t_sample mul_51 = (mul_56 * sub_24);
		t_sample sub_118 = (mul_51 - ((int)0));
		t_sample scale_115 = ((safepow((sub_118 * ((t_sample)1)), ((int)1)) * ((int)2980)) + ((int)20));
		t_sample mul_50 = (mul_51 * sub_24);
		t_sample sub_126 = (mul_50 - ((int)0));
		t_sample scale_123 = ((safepow((sub_126 * ((t_sample)1)), ((int)1)) * ((int)2980)) + ((int)20));
		t_sample mul_22 = (mul_50 * sub_24);
		t_sample sub_134 = (mul_22 - ((int)0));
		t_sample scale_131 = ((safepow((sub_134 * ((t_sample)1)), ((int)1)) * ((int)2980)) + ((int)20));
		t_sample add_25 = (scale_87 + ((int)1));
		t_sample mul_47 = (pow_19 * add_25);
		t_sample sub_142 = (mul_47 - ((int)0));
		t_sample scale_139 = ((safepow((sub_142 * ((t_sample)1)), ((int)1)) * ((int)2980)) + ((int)20));
		t_sample mul_44 = (mul_47 * add_25);
		t_sample sub_150 = (mul_44 - ((int)0));
		t_sample scale_147 = ((safepow((sub_150 * ((t_sample)1)), ((int)1)) * ((int)2980)) + ((int)20));
		t_sample mul_41 = (mul_44 * add_25);
		t_sample sub_158 = (mul_41 - ((int)0));
		t_sample scale_155 = ((safepow((sub_158 * ((t_sample)1)), ((int)1)) * ((int)2980)) + ((int)20));
		t_sample mul_36 = (mul_41 * add_25);
		t_sample sub_166 = (mul_36 - ((int)0));
		t_sample scale_163 = ((safepow((sub_166 * ((t_sample)1)), ((int)1)) * ((int)2980)) + ((int)20));
		t_sample mul_35 = (mul_36 * add_25);
		t_sample sub_174 = (mul_35 - ((int)0));
		t_sample scale_171 = ((safepow((sub_174 * ((t_sample)1)), ((int)1)) * ((int)2980)) + ((int)20));
		t_sample mul_32 = (mul_35 * add_25);
		t_sample sub_182 = (mul_32 - ((int)0));
		t_sample scale_179 = ((safepow((sub_182 * ((t_sample)1)), ((int)1)) * ((int)2980)) + ((int)20));
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			t_sample mul_16 = (in1 * m_D_1);
			t_sample expr_73 = moogLadder_d_d_i(mul_16, cf, res);
			t_sample out1 = expr_73;
			t_sample phasor_65 = __m_phasor_13(scale_79, samples_to_seconds);
			t_sample sub_86 = (phasor_65 - ((int)0));
			t_sample scale_83 = ((safepow((sub_86 * ((t_sample)1)), ((int)1)) * ((int)2)) + (-1));
			t_sample phasor_62 = __m_phasor_14(scale_91, samples_to_seconds);
			t_sample sub_98 = (phasor_62 - ((int)0));
			t_sample scale_95 = ((safepow((sub_98 * ((t_sample)1)), ((int)1)) * ((int)2)) + (-1));
			t_sample phasor_57 = __m_phasor_15(scale_99, samples_to_seconds);
			t_sample sub_106 = (phasor_57 - ((int)0));
			t_sample scale_103 = ((safepow((sub_106 * ((t_sample)1)), ((int)1)) * ((int)2)) + (-1));
			t_sample phasor_54 = __m_phasor_16(scale_107, samples_to_seconds);
			t_sample sub_114 = (phasor_54 - ((int)0));
			t_sample scale_111 = ((safepow((sub_114 * ((t_sample)1)), ((int)1)) * ((int)2)) + (-1));
			t_sample phasor_52 = __m_phasor_17(scale_115, samples_to_seconds);
			t_sample sub_122 = (phasor_52 - ((int)0));
			t_sample scale_119 = ((safepow((sub_122 * ((t_sample)1)), ((int)1)) * ((int)2)) + (-1));
			t_sample phasor_48 = __m_phasor_18(scale_123, samples_to_seconds);
			t_sample sub_130 = (phasor_48 - ((int)0));
			t_sample scale_127 = ((safepow((sub_130 * ((t_sample)1)), ((int)1)) * ((int)2)) + (-1));
			t_sample phasor_20 = __m_phasor_19(scale_131, samples_to_seconds);
			t_sample sub_138 = (phasor_20 - ((int)0));
			t_sample scale_135 = ((safepow((sub_138 * ((t_sample)1)), ((int)1)) * ((int)2)) + (-1));
			t_sample phasor_45 = __m_phasor_20(scale_139, samples_to_seconds);
			t_sample sub_146 = (phasor_45 - ((int)0));
			t_sample scale_143 = ((safepow((sub_146 * ((t_sample)1)), ((int)1)) * ((int)2)) + (-1));
			t_sample phasor_42 = __m_phasor_21(scale_147, samples_to_seconds);
			t_sample sub_154 = (phasor_42 - ((int)0));
			t_sample scale_151 = ((safepow((sub_154 * ((t_sample)1)), ((int)1)) * ((int)2)) + (-1));
			t_sample phasor_39 = __m_phasor_22(scale_155, samples_to_seconds);
			t_sample sub_162 = (phasor_39 - ((int)0));
			t_sample scale_159 = ((safepow((sub_162 * ((t_sample)1)), ((int)1)) * ((int)2)) + (-1));
			t_sample phasor_37 = __m_phasor_23(scale_163, samples_to_seconds);
			t_sample sub_170 = (phasor_37 - ((int)0));
			t_sample scale_167 = ((safepow((sub_170 * ((t_sample)1)), ((int)1)) * ((int)2)) + (-1));
			t_sample phasor_33 = __m_phasor_24(scale_171, samples_to_seconds);
			t_sample sub_178 = (phasor_33 - ((int)0));
			t_sample scale_175 = ((safepow((sub_178 * ((t_sample)1)), ((int)1)) * ((int)2)) + (-1));
			t_sample phasor_30 = __m_phasor_25(scale_179, samples_to_seconds);
			t_sample sub_186 = (phasor_30 - ((int)0));
			t_sample scale_183 = ((safepow((sub_186 * ((t_sample)1)), ((int)1)) * ((int)2)) + (-1));
			t_sample add_26 = (((((((((((((scale_183 + scale_159) + scale_167) + scale_175) + scale_135) + scale_143) + scale_151) + scale_111) + scale_119) + scale_127) + scale_103) + scale_95) + scale_83) + ((int)0));
			t_sample div_2 = (add_26 * ((t_sample)0.11111111111111));
			t_sample out2 = div_2;
			// assign results to output buffer;
			(*(__out1++)) = out1;
			(*(__out2++)) = out2;
			
		};
		return __exception;
		
	};
	inline void set_D(t_param _value) {
		m_D_1 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_B(t_param _value) {
		m_B_2 = (_value < 1e-06 ? 1e-06 : (_value > 1 ? 1 : _value));
	};
	inline void set_C(t_param _value) {
		m_C_3 = (_value < 0.0001 ? 0.0001 : (_value > 1 ? 1 : _value));
	};
	inline void set_A(t_param _value) {
		m_A_4 = (_value < 1e-06 ? 1e-06 : (_value > 1 ? 1 : _value));
	};
	inline t_sample moogLadder_d_d_i(t_sample asig, t_sample cf, int res) {
		int i2v = ((int)40000);
		t_sample akfc = safediv(cf, (samplerate * ((t_sample)0.5)));
		t_sample akf = safediv(cf, samplerate);
		t_sample fcr = ((((((t_sample)1.873) * safepow(akfc, ((int)3))) + (((t_sample)0.4955) * safepow(akfc, ((int)2)))) - (((t_sample)0.649) * akfc)) + ((t_sample)0.9988));
		t_sample acr = ((((-((t_sample)3.9364)) * safepow(akfc, ((int)2))) + (((t_sample)1.8409) * akfc)) + ((t_sample)0.9968));
		t_sample twovg = (i2v * (((int)1) - exp(((((-((int)2)) * ((t_sample)3.1415926535898)) * fcr) * akf))));
		t_sample y1 = (m_z_12 + (twovg * (tanh(safediv((asig - (((((int)4) * res) * m_mf_6) * acr)), i2v)) - tanh(safediv(m_z_12, i2v)))));
		m_z_12 = y1;
		t_sample y2 = (m_z_11 + (twovg * (tanh(safediv(y1, i2v)) - tanh(safediv(m_z_11, i2v)))));
		m_z_11 = y2;
		t_sample y3 = (m_z_10 + (twovg * (tanh(safediv(y2, i2v)) - tanh(safediv(m_z_10, i2v)))));
		m_z_10 = y3;
		m_y_7 = (m_z_9 + (twovg * (tanh(safediv(y3, i2v)) - tanh(safediv(m_z_9, i2v)))));
		m_z_9 = m_y_7;
		m_mf_6 = ((m_y_7 + m_z_8) * ((t_sample)0.5));
		m_z_8 = m_y_7;
		return m_mf_6;
		
	};
	
} State;


///
///	Configuration for the genlib API
///

/// Number of signal inputs and outputs

int gen_kernel_numins = 1;
int gen_kernel_numouts = 2;

int num_inputs() { return gen_kernel_numins; }
int num_outputs() { return gen_kernel_numouts; }
int num_params() { return 4; }

/// Assistive lables for the signal inputs and outputs

const char *gen_kernel_innames[] = { "in1" };
const char *gen_kernel_outnames[] = { "out1", "out2" };

/// Invoke the signal process of a State object

int perform(CommonState *cself, t_sample **ins, long numins, t_sample **outs, long numouts, long n) {
	State* self = (State *)cself;
	return self->perform(ins, outs, n);
}

/// Reset all parameters and stateful operators of a State object

void reset(CommonState *cself) {
	State* self = (State *)cself;
	self->reset(cself->sr, cself->vs);
}

/// Set a parameter of a State object

void setparameter(CommonState *cself, long index, t_param value, void *ref) {
	State *self = (State *)cself;
	switch (index) {
		case 0: self->set_A(value); break;
		case 1: self->set_B(value); break;
		case 2: self->set_C(value); break;
		case 3: self->set_D(value); break;
		
		default: break;
	}
}

/// Get the value of a parameter of a State object

void getparameter(CommonState *cself, long index, t_param *value) {
	State *self = (State *)cself;
	switch (index) {
		case 0: *value = self->m_A_4; break;
		case 1: *value = self->m_B_2; break;
		case 2: *value = self->m_C_3; break;
		case 3: *value = self->m_D_1; break;
		
		default: break;
	}
}

/// Get the name of a parameter of a State object

const char *getparametername(CommonState *cself, long index) {
	if (index >= 0 && index < cself->numparams) {
		return cself->params[index].name;
	}
	return 0;
}

/// Get the minimum value of a parameter of a State object

t_param getparametermin(CommonState *cself, long index) {
	if (index >= 0 && index < cself->numparams) {
		return cself->params[index].outputmin;
	}
	return 0;
}

/// Get the maximum value of a parameter of a State object

t_param getparametermax(CommonState *cself, long index) {
	if (index >= 0 && index < cself->numparams) {
		return cself->params[index].outputmax;
	}
	return 0;
}

/// Get parameter of a State object has a minimum and maximum value

char getparameterhasminmax(CommonState *cself, long index) {
	if (index >= 0 && index < cself->numparams) {
		return cself->params[index].hasminmax;
	}
	return 0;
}

/// Get the units of a parameter of a State object

const char *getparameterunits(CommonState *cself, long index) {
	if (index >= 0 && index < cself->numparams) {
		return cself->params[index].units;
	}
	return 0;
}

/// Get the size of the state of all parameters of a State object

size_t getstatesize(CommonState *cself) {
	return genlib_getstatesize(cself, &getparameter);
}

/// Get the state of all parameters of a State object

short getstate(CommonState *cself, char *state) {
	return genlib_getstate(cself, state, &getparameter);
}

/// set the state of all parameters of a State object

short setstate(CommonState *cself, const char *state) {
	return genlib_setstate(cself, state, &setparameter);
}

/// Allocate and configure a new State object and it's internal CommonState:

void *create(t_param sr, long vs) {
	State *self = new State;
	self->reset(sr, vs);
	ParamInfo *pi;
	self->__commonstate.inputnames = gen_kernel_innames;
	self->__commonstate.outputnames = gen_kernel_outnames;
	self->__commonstate.numins = gen_kernel_numins;
	self->__commonstate.numouts = gen_kernel_numouts;
	self->__commonstate.sr = sr;
	self->__commonstate.vs = vs;
	self->__commonstate.params = (ParamInfo *)genlib_sysmem_newptr(4 * sizeof(ParamInfo));
	self->__commonstate.numparams = 4;
	// initialize parameter 0 ("m_A_4")
	pi = self->__commonstate.params + 0;
	pi->name = "A";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_A_4;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 1e-06;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_B_2")
	pi = self->__commonstate.params + 1;
	pi->name = "B";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_B_2;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 1e-06;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_C_3")
	pi = self->__commonstate.params + 2;
	pi->name = "C";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_C_3;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0.0001;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_D_1")
	pi = self->__commonstate.params + 3;
	pi->name = "D";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_D_1;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	
	return self;
}

/// Release all resources and memory used by a State object:

void destroy(CommonState *cself) {
	State *self = (State *)cself;
	genlib_sysmem_freeptr(cself->params);
		
	delete self;
}


} // SwarmaAndLadder::
