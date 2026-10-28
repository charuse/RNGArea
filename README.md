# RNGArea
### Random on/off SW_A

|Var|Desc||
|------|--------------|------|
|Obj_arg0|Value controls chance|(I.E. 50 would be 50% chance, 30 for 30%)|
|SW_A|Turn on if Generated Number <= Obj_arg0|Chance determined by Obj_arg0|

#### *Runs once per life upon entering the area*  

Returns random number 1-100  
Seeds with current OS tick  
<br>

### LCG:
```cpp
class TRandom_fast_ {
public:
	TRandom_fast_(u32);

	inline u32 rand() {
		return mSeed = 0x19660D * mSeed + 0x3C6EF35F;
	}

	u32 mSeed;
};
```