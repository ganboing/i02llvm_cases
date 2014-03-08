; ModuleID = 'hello.c'
target datalayout = "e-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:32:64-f32:32:32-f64:32:64-v64:64:64-v128:128:128-a0:0:64-f80:32:32-n8:16:32-S128"
target triple = "i386-pc-linux-gnu"

; Function Attrs: nounwind
define i32 @test(i32 %a) #0 {
  %1 = alloca i32, align 4
  %ret = alloca i32, align 4
  store i32 %a, i32* %1, align 4
  store i32 43981, i32* %ret, align 4
  %2 = load i32* %1, align 4
  %3 = icmp sgt i32 %2, 0
  br i1 %3, label %4, label %5

; <label>:4                                       ; preds = %0
  store i32 1, i32* %ret, align 4
  br label %6

; <label>:5                                       ; preds = %0
  store i32 0, i32* %ret, align 4
  br label %6

; <label>:6                                       ; preds = %5, %4
  %7 = load i32* %ret, align 4
  ret i32 %7
}

attributes #0 = { nounwind "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf"="true" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "unsafe-fp-math"="false" "use-soft-float"="false" }
