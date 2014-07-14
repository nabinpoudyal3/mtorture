# include "MPlexTest.h"

//==============================================================================

MPlexTest::MPlexTest(int n_array, int size)
{
  fMPV = new MPV*[n_array];
  fN   = n_array;

  for (int i = 0; i < fN; ++i)
  {
    fMPV[i] = new MPV(size);
  }
}

MPlexTest::~MPlexTest()
{
  for (int i = 0; i < fN; ++i)
  {
    delete fMPV[i];
  }
  delete fMPV;
}

//==============================================================================

int MPlexTest::mult2(int n_vec)
{
  Matriplex::MultiplyUnrolled(*fMPV[0], *fMPV[1], *fMPV[2], n_vec);

  return (2 * 6*6*6 - 6*6) * 16 * n_vec;// XXXX
}

int MPlexTest::mult2_3out(int n_vec)
{
  Matriplex::Multiply(*fMPV[0], *fMPV[1], *fMPV[2], n_vec);
  Matriplex::Multiply(*fMPV[1], *fMPV[2], *fMPV[0], n_vec);
  Matriplex::Multiply(*fMPV[2], *fMPV[0], *fMPV[1], n_vec);

  return 3 * (2 * 6*6*6 - 6*6) * 16 * n_vec;// XXXX
}

int MPlexTest::mult2_3in(int n_vec)
{
  Matriplex::Multiply3in(*fMPV[0], *fMPV[1], *fMPV[2], n_vec);

  return 3 * (2 * 6*6*6 - 6*6) * 16 * n_vec;// XXXX
}
