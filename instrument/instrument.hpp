 #ifndef INSTRUMENT_H
#define INSTRUMENT_H

#include "instrument_data.hpp"

/* sets up the structure for your Instrument class, which will handle specific logic in your project. 
You’ll fill in the process function with the behavior you want your instrument to have.
*/

class Instrument
{

	public:
		Instrument() = default;		// default constructor
		~Instrument() = default;	// default destructor

		void process(const InstrumentInputData& data, InstrumentOutputData& output);

	private:
		bool state = false; 
};

#endif // INSTRUMENT_H