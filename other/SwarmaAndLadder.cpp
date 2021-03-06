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
	t_sample m_A_2;
	t_sample samples_to_seconds;
	t_sample m_D_3;
	t_sample m_C_1;
	t_sample samplerate;
	t_sample m_z_11;
	t_sample m_B_4;
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
		m_C_1 = ((int)0);
		m_A_2 = ((int)0);
		m_D_3 = ((int)0);
		m_B_4 = ((int)0);
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
		t_sample pow_931 = safepow(m_C_1, ((int)2));
		t_sample sub_1234 = (pow_931 - ((int)0));
		t_sample scale_1231 = ((safepow((sub_1234 * ((t_sample)1)), ((int)1)) * ((int)19980)) + ((int)20));
		t_sample max_5 = (samplerate * ((t_sample)0.25));
		t_sample cf = ((scale_1231 <= ((int)20)) ? ((int)20) : ((scale_1231 >= max_5) ? max_5 : scale_1231));
		int res = ((((int)0) <= ((int)0)) ? ((int)0) : ((((int)0) >= ((int)1)) ? ((int)1) : ((int)0)));
		t_sample pow_933 = safepow(m_A_2, ((int)2));
		t_sample sub_1238 = (pow_933 - ((int)0));
		t_sample scale_1235 = ((safepow((sub_1238 * ((t_sample)1)), ((int)1)) * ((int)2980)) + ((int)20));
		samples_to_seconds = (1 / samplerate);
		t_sample pow_932 = safepow(m_B_4, ((int)2));
		t_sample sub_1246 = (pow_932 - ((int)0));
		t_sample scale_1243 = ((safepow((sub_1246 * ((t_sample)1)), ((int)1)) * ((t_sample)0.3)) + ((int)0));
		t_sample sub_938 = (((int)1) - scale_1243);
		t_sample mul_975 = (pow_933 * sub_938);
		t_sample sub_1250 = (mul_975 - ((int)0));
		t_sample scale_1247 = ((safepow((sub_1250 * ((t_sample)1)), ((int)1)) * ((int)2980)) + ((int)20));
		t_sample mul_973 = (mul_975 * sub_938);
		t_sample sub_1258 = (mul_973 - ((int)0));
		t_sample scale_1255 = ((safepow((sub_1258 * ((t_sample)1)), ((int)1)) * ((int)2980)) + ((int)20));
		t_sample mul_970 = (mul_973 * sub_938);
		t_sample sub_1266 = (mul_970 - ((int)0));
		t_sample scale_1263 = ((safepow((sub_1266 * ((t_sample)1)), ((int)1)) * ((int)2980)) + ((int)20));
		t_sample mul_965 = (mul_970 * sub_938);
		t_sample sub_1274 = (mul_965 - ((int)0));
		t_sample scale_1271 = ((safepow((sub_1274 * ((t_sample)1)), ((int)1)) * ((int)2980)) + ((int)20));
		t_sample mul_964 = (mul_965 * sub_938);
		t_sample sub_1282 = (mul_964 - ((int)0));
		t_sample scale_1279 = ((safepow((sub_1282 * ((t_sample)1)), ((int)1)) * ((int)2980)) + ((int)20));
		t_sample mul_936 = (mul_964 * sub_938);
		t_sample sub_1290 = (mul_936 - ((int)0));
		t_sample scale_1287 = ((safepow((sub_1290 * ((t_sample)1)), ((int)1)) * ((int)2980)) + ((int)20));
		t_sample add_939 = (scale_1243 + ((int)1));
		t_sample mul_961 = (pow_933 * add_939);
		t_sample sub_1298 = (mul_961 - ((int)0));
		t_sample scale_1295 = ((safepow((sub_1298 * ((t_sample)1)), ((int)1)) * ((int)2980)) + ((int)20));
		t_sample mul_958 = (mul_961 * add_939);
		t_sample sub_1306 = (mul_958 - ((int)0));
		t_sample scale_1303 = ((safepow((sub_1306 * ((t_sample)1)), ((int)1)) * ((int)2980)) + ((int)20));
		t_sample mul_955 = (mul_958 * add_939);
		t_sample sub_1314 = (mul_955 - ((int)0));
		t_sample scale_1311 = ((safepow((sub_1314 * ((t_sample)1)), ((int)1)) * ((int)2980)) + ((int)20));
		t_sample mul_950 = (mul_955 * add_939);
		t_sample sub_1322 = (mul_950 - ((int)0));
		t_sample scale_1319 = ((safepow((sub_1322 * ((t_sample)1)), ((int)1)) * ((int)2980)) + ((int)20));
		t_sample mul_949 = (mul_950 * add_939);
		t_sample sub_1330 = (mul_949 - ((int)0));
		t_sample scale_1327 = ((safepow((sub_1330 * ((t_sample)1)), ((int)1)) * ((int)2980)) + ((int)20));
		t_sample mul_946 = (mul_949 * add_939);
		t_sample sub_1338 = (mul_946 - ((int)0));
		t_sample scale_1335 = ((safepow((sub_1338 * ((t_sample)1)), ((int)1)) * ((int)2980)) + ((int)20));
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			t_sample mul_994 = (in1 * m_D_3);
			t_sample expr_1005 = moogLadder_d_d_i(mul_994, cf, res);
			t_sample out1 = expr_1005;
			t_sample phasor_979 = __m_phasor_13(scale_1235, samples_to_seconds);
			t_sample sub_1242 = (phasor_979 - ((int)0));
			t_sample scale_1239 = ((safepow((sub_1242 * ((t_sample)1)), ((int)1)) * ((int)2)) + (-1));
			t_sample phasor_976 = __m_phasor_14(scale_1247, samples_to_seconds);
			t_sample sub_1254 = (phasor_976 - ((int)0));
			t_sample scale_1251 = ((safepow((sub_1254 * ((t_sample)1)), ((int)1)) * ((int)2)) + (-1));
			t_sample phasor_971 = __m_phasor_15(scale_1255, samples_to_seconds);
			t_sample sub_1262 = (phasor_971 - ((int)0));
			t_sample scale_1259 = ((safepow((sub_1262 * ((t_sample)1)), ((int)1)) * ((int)2)) + (-1));
			t_sample phasor_968 = __m_phasor_16(scale_1263, samples_to_seconds);
			t_sample sub_1270 = (phasor_968 - ((int)0));
			t_sample scale_1267 = ((safepow((sub_1270 * ((t_sample)1)), ((int)1)) * ((int)2)) + (-1));
			t_sample phasor_966 = __m_phasor_17(scale_1271, samples_to_seconds);
			t_sample sub_1278 = (phasor_966 - ((int)0));
			t_sample scale_1275 = ((safepow((sub_1278 * ((t_sample)1)), ((int)1)) * ((int)2)) + (-1));
			t_sample phasor_962 = __m_phasor_18(scale_1279, samples_to_seconds);
			t_sample sub_1286 = (phasor_962 - ((int)0));
			t_sample scale_1283 = ((safepow((sub_1286 * ((t_sample)1)), ((int)1)) * ((int)2)) + (-1));
			t_sample phasor_934 = __m_phasor_19(scale_1287, samples_to_seconds);
			t_sample sub_1294 = (phasor_934 - ((int)0));
			t_sample scale_1291 = ((safepow((sub_1294 * ((t_sample)1)), ((int)1)) * ((int)2)) + (-1));
			t_sample phasor_959 = __m_phasor_20(scale_1295, samples_to_seconds);
			t_sample sub_1302 = (phasor_959 - ((int)0));
			t_sample scale_1299 = ((safepow((sub_1302 * ((t_sample)1)), ((int)1)) * ((int)2)) + (-1));
			t_sample phasor_956 = __m_phasor_21(scale_1303, samples_to_seconds);
			t_sample sub_1310 = (phasor_956 - ((int)0));
			t_sample scale_1307 = ((safepow((sub_1310 * ((t_sample)1)), ((int)1)) * ((int)2)) + (-1));
			t_sample phasor_953 = __m_phasor_22(scale_1311, samples_to_seconds);
			t_sample sub_1318 = (phasor_953 - ((int)0));
			t_sample scale_1315 = ((safepow((sub_1318 * ((t_sample)1)), ((int)1)) * ((int)2)) + (-1));
			t_sample phasor_951 = __m_phasor_23(scale_1319, samples_to_seconds);
			t_sample sub_1326 = (phasor_951 - ((int)0));
			t_sample scale_1323 = ((safepow((sub_1326 * ((t_sample)1)), ((int)1)) * ((int)2)) + (-1));
			t_sample phasor_947 = __m_phasor_24(scale_1327, samples_to_seconds);
			t_sample sub_1334 = (phasor_947 - ((int)0));
			t_sample scale_1331 = ((safepow((sub_1334 * ((t_sample)1)), ((int)1)) * ((int)2)) + (-1));
			t_sample phasor_944 = __m_phasor_25(scale_1335, samples_to_seconds);
			t_sample sub_1342 = (phasor_944 - ((int)0));
			t_sample scale_1339 = ((safepow((sub_1342 * ((t_sample)1)), ((int)1)) * ((int)2)) + (-1));
			t_sample add_940 = (((((((((((((scale_1339 + scale_1315) + scale_1323) + scale_1331) + scale_1291) + scale_1299) + scale_1307) + scale_1267) + scale_1275) + scale_1283) + scale_1259) + scale_1251) + scale_1239) + ((int)0));
			t_sample div_916 = (add_940 * ((t_sample)0.11111111111111));
			t_sample out2 = div_916;
			// assign results to output buffer;
			(*(__out1++)) = out1;
			(*(__out2++)) = out2;
			
		};
		return __exception;
		
	};
	inline void set_C(t_param _value) {
		m_C_1 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_A(t_param _value) {
		m_A_2 = (_value < 1e-06 ? 1e-06 : (_value > 1 ? 1 : _value));
	};
	inline void set_D(t_param _value) {
		m_D_3 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_B(t_param _value) {
		m_B_4 = (_value < 1e-06 ? 1e-06 : (_value > 1 ? 1 : _value));
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
		case 0: *value = self->m_A_2; break;
		case 1: *value = self->m_B_4; break;
		case 2: *value = self->m_C_1; break;
		case 3: *value = self->m_D_3; break;
		
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
	// initialize parameter 0 ("m_A_2")
	pi = self->__commonstate.params + 0;
	pi->name = "A";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_A_2;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 1e-06;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_B_4")
	pi = self->__commonstate.params + 1;
	pi->name = "B";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_B_4;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 1e-06;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_C_1")
	pi = self->__commonstate.params + 2;
	pi->name = "C";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_C_1;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_D_3")
	pi = self->__commonstate.params + 3;
	pi->name = "D";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_D_3;
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
