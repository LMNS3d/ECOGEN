//  
//       ,---.     ,--,    .---.     ,--,    ,---.    .-. .-. 
//       | .-'   .' .')   / .-. )  .' .'     | .-'    |  \| | 
//       | `-.   |  |(_)  | | |(_) |  |  __  | `-.    |   | | 
//       | .-'   \  \     | | | |  \  \ ( _) | .-'    | |\  | 
//       |  `--.  \  `-.  \ `-' /   \  `-) ) |  `--.  | | |)| 
//       /( __.'   \____\  )---'    )\____/  /( __.'  /(  (_) 
//      (__)              (_)      (__)     (__)     (__)     
//
//  This file is part of ECOGEN.
//
//  ECOGEN is the legal property of its developers, whose names 
//  are listed in the copyright file included with this source 
//  distribution.
//
//  ECOGEN is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published 
//  by the Free Software Foundation, either version 3 of the License, 
//  or (at your option) any later version.
//  
//  ECOGEN is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
//  GNU General Public License for more details.
//  
//  You should have received a copy of the GNU General Public License
//  along with ECOGEN (file LICENSE).  
//  If not, see <http://www.gnu.org/licenses/>.

#include "FacePoint.h"

using namespace std;

const int FacePoint::NOMBRENOEUDS = 1;

//***********************************************************************

FacePoint::FacePoint(const int &numNoeud1) :
FaceNS(NOMBRENOEUDS)
{
  m_numNoeuds[0] = numNoeud1;
  m_sommeNumNoeuds = m_numNoeuds[0];
}

//***********************************************************************

FacePoint::~FacePoint(){}

//***********************************************************************

void FacePoint::calculSurface(const Coord *noeuds)
{
  m_surface = 1.0; //unite
}

//***********************************************************************

void FacePoint::calculRepere(const Coord *noeuds, const int &numNoeudAutre, ElementNS *elementVoisin)
{
  Coord v1; v1.creeVecteur(noeuds[m_numNoeuds[0]], noeuds[numNoeudAutre]);
  m_normale = v1 / v1.norme();
  m_binormale.setXYZ(0., 0., 1.);
  m_tangente = Coord::produitVectoriel(m_binormale, m_normale);

  m_elementDroite = elementVoisin;
  m_elementGauche = 0;
}

//***********************************************************************