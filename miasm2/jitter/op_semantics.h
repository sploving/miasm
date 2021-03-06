#ifndef OP_SEMANTICS_H
#define OP_SEMANTICS_H

#define uint128_t __uint128_t
#define int128_t __int128_t

#define CC_P 1
extern const uint8_t parity_table[256];
#define parity(a) parity_table[(a) & 0xFF]

unsigned int my_imul08(unsigned int a, unsigned int b);
unsigned int mul_lo_op(unsigned int size, unsigned int a, unsigned int b);
unsigned int mul_hi_op(unsigned int size, unsigned int a, unsigned int b);
unsigned int imul_lo_op_08(char a, char b);
unsigned int imul_lo_op_16(short a, short b);
unsigned int imul_lo_op_32(int a, int b);
int imul_hi_op_08(char a, char b);
int imul_hi_op_16(short a, short b);
int imul_hi_op_32(int a, int b);


unsigned int umul16_lo(unsigned short a, unsigned short b);
unsigned int umul16_hi(unsigned short a, unsigned short b);


uint64_t rot_left(uint64_t size, uint64_t a, uint64_t b);
uint64_t rot_right(uint64_t size, uint64_t a, uint64_t b);

unsigned int cntleadzeros(uint64_t size, uint64_t src);
unsigned int cnttrailzeros(uint64_t size, uint64_t src);

#define UDIV(sizeA)						\
	uint ## sizeA ## _t udiv ## sizeA (uint ## sizeA ## _t a, uint ## sizeA ## _t b) \
	{								\
		uint ## sizeA ## _t r;					\
		if (b == 0) {						\
			fprintf(stderr, "Should not happen\n");		\
			exit(EXIT_FAILURE);				\
		}							\
		r = a/b;						\
		return r;						\
	}


#define UMOD(sizeA)						\
	uint ## sizeA ## _t umod ## sizeA (uint ## sizeA ## _t a, uint ## sizeA ## _t b) \
	{								\
		uint ## sizeA ## _t r;					\
		if (b == 0) {						\
			fprintf(stderr, "Should not happen\n");		\
			exit(EXIT_FAILURE);				\
		}							\
		r = a%b;						\
		return r;						\
	}


#define IDIV(sizeA)						\
	int ## sizeA ## _t idiv ## sizeA (int ## sizeA ## _t a, int ## sizeA ## _t b) \
	{								\
		int ## sizeA ## _t r;					\
		if (b == 0) {						\
			fprintf(stderr, "Should not happen\n");		\
			exit(EXIT_FAILURE);				\
		}							\
		r = a/b;						\
		return r;						\
	}


#define IMOD(sizeA)						\
	int ## sizeA ## _t imod ## sizeA (int ## sizeA ## _t a, int ## sizeA ## _t b) \
	{								\
		int ## sizeA ## _t r;					\
		if (b == 0) {						\
			fprintf(stderr, "Should not happen\n");		\
			exit(EXIT_FAILURE);				\
		}							\
		r = a%b;						\
		return r;						\
	}

uint64_t udiv64(uint64_t a, uint64_t b);
uint64_t umod64(uint64_t a, uint64_t b);
int64_t idiv64(int64_t a, int64_t b);
int64_t imod64(int64_t a, int64_t b);

uint32_t udiv32(uint32_t a, uint32_t b);
uint32_t umod32(uint32_t a, uint32_t b);
int32_t idiv32(int32_t a, int32_t b);
int32_t imod32(int32_t a, int32_t b);

uint16_t udiv16(uint16_t a, uint16_t b);
uint16_t umod16(uint16_t a, uint16_t b);
int16_t idiv16(int16_t a, int16_t b);
int16_t imod16(int16_t a, int16_t b);

unsigned int x86_cpuid(unsigned int a, unsigned int reg_num);

uint32_t fpu_fadd32(uint32_t a, uint32_t b);
uint64_t fpu_fadd64(uint64_t a, uint64_t b);
uint32_t fpu_fsub32(uint32_t a, uint32_t b);
uint64_t fpu_fsub64(uint64_t a, uint64_t b);
uint32_t fpu_fmul32(uint32_t a, uint32_t b);
uint64_t fpu_fmul64(uint64_t a, uint64_t b);
uint32_t fpu_fdiv32(uint32_t a, uint32_t b);
uint64_t fpu_fdiv64(uint64_t a, uint64_t b);
double fpu_ftan(double a);
double fpu_frndint(double a);
double fpu_fsin(double a);
double fpu_fcos(double a);
double fpu_fscale(double a, double b);
double fpu_f2xm1(double a);
uint32_t fpu_fsqrt32(uint32_t a);
uint64_t fpu_fsqrt64(uint64_t a);
double fpu_fabs(double a);
double fpu_fprem(double a, double b);
double fpu_fchs(double a);
double fpu_fyl2x(double a, double b);
double fpu_fpatan(double a, double b);
unsigned int fpu_fprem_lsb(double a, double b);
unsigned int fpu_fcom_c0(double a, double b);
unsigned int fpu_fcom_c1(double a, double b);
unsigned int fpu_fcom_c2(double a, double b);
unsigned int fpu_fcom_c3(double a, double b);
unsigned int fpu_fxam_c0(double a);
unsigned int fpu_fxam_c1(double a);
unsigned int fpu_fxam_c2(double a);
unsigned int fpu_fxam_c3(double a);

uint64_t sint64_to_fp64(int64_t a);
uint32_t sint32_to_fp32(int32_t a);
uint64_t sint32_to_fp64(int32_t a);
int32_t fp32_to_sint32(uint32_t a);
int64_t fp64_to_sint64(uint64_t a);
int32_t fp64_to_sint32(uint64_t a);
uint32_t fp64_to_fp32(uint64_t a);
uint64_t fp32_to_fp64(uint32_t a);
uint32_t fpround_towardszero_fp32(uint32_t a);
uint64_t fpround_towardszero_fp64(uint64_t a);

#define SHIFT_RIGHT_ARITH(size, value, shift)				\
	((uint ## size ## _t)((((uint64_t) (shift)) > ((size) - 1))?	\
			      (((int ## size ## _t) (value)) < 0 ? -1 : 0) : \
			      (((int ## size ## _t) (value)) >> (shift))))

#define SHIFT_RIGHT_LOGIC(size, value, shift)				\
	((uint ## size ## _t)((((uint64_t) (shift)) > ((size) - 1))?	\
			      0 :					\
			      (((uint ## size ## _t) (value)) >> (shift))))

#define SHIFT_LEFT_LOGIC(size, value, shift)		\
	((uint ## size ## _t)((((uint64_t) (shift)) > ((size) - 1))?	\
			      0 :					\
			      (((uint ## size ## _t) (value)) << (shift))))

#endif
