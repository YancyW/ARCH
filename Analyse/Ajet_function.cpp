#include "Ajet_function.h"

//--------------------------------------------
std::vector<double> JeT_DeltaR( Jet* jet, std::string kind){
	std::vector <double> dr;
	if(kind=="central jet"){
        dr=JeT_DeltaR_central(jet);
	}
	else if(kind=="leading jet"){
        dr=JeT_DeltaR_leading(jet);
	}
	return(dr);
}

std::vector<double> JeT_DeltaR_central( Jet* jet){
	std::vector <double> dr;
	double_t Eta=jet->Eta;
	double_t Phi=jet->Phi;
	std::vector<fastjet::PseudoJet> jet_constituents  = make_PseudoJet_constituents(jet);

	for(int i=0;i<=jet->Constituents.GetEntriesFast();i++){
		fastjet::PseudoJet component = jet_constituents[i];

		double dR = DeltaR(Eta,Phi, component.eta(), component.phi());

		dr.push_back(dR);
	}//endfor consti_Cindex

	return(dr);
}

std::vector<double> JeT_DeltaR_leading( Jet* jet){
	std::vector <double> dr;
	fastjet::PseudoJet leading_constituent = Jet_Find_LeadingConstituent(jet);
	std::vector<fastjet::PseudoJet> jet_constituents  = make_PseudoJet_constituents(jet);

	for(int i=0;i<=jet->Constituents.GetEntriesFast();i++){
		fastjet::PseudoJet component = jet_constituents[i];

		double dR = DeltaR(leading_constituent, component);
		dr.push_back(dR);
	}//endfor consti_Cindex

	return(dr);
}

fastjet::PseudoJet Jet_Find_LeadingConstituent(Jet* jet){
	std::vector<fastjet::PseudoJet> jet_constituents  = make_PseudoJet_constituents(jet);
    std::vector<fastjet::PseudoJet> consitituent_collection = fastjet::sorted_by_pt(jet_constituents);
    fastjet::PseudoJet fast_leading_constituent= consitituent_collection[0];
	return(fast_leading_constituent);
}


//--------------------------------------------
double DeltaR(double_t eta1, double_t phi1,double_t eta2, double_t phi2)
{
	double deltaPhi = std::abs(phi1-phi2);
	double deltaEta = eta1-eta2;
	if(deltaPhi > 3.1415926)
		deltaPhi = 2*3.1415926 - deltaPhi;
	return sqrt(deltaEta*deltaEta + deltaPhi*deltaPhi);
}

//--------------------------------------------
double DeltaR( fastjet::PseudoJet jet1, fastjet::PseudoJet jet2)
{
	double deltaPhi = std::abs(jet1.phi()-jet2.phi());
	double deltaEta = jet1.eta()-jet2.eta();
	if(deltaPhi > 3.1415926){
		deltaPhi = 2*3.1415926 - deltaPhi;
	}
	double _r = sqrt(deltaEta*deltaEta + deltaPhi*deltaPhi);
	return(_r);
////double mag2_1=std::pow(2,jet1.px())+std::pow(2,jet1.py())+std::pow(2,jet1.pz());
////double mag2_2=std::pow(2,jet2.px())+std::pow(2,jet2.py())+std::pow(2,jet2.pz());
////double ptot2 = mag2_1*mag2_2;
////double dotq = jet1.px()*jet2.px()+jet1.py()*jet2.py()+jet1.pz()*jet2.pz();
////if(ptot2 <= 0) {
////   return 0.0;
////} 
////else {
////    double arg = dotq/std::sqrt(ptot2);
////    if(arg >  1.0) arg =  1.0;
////    if(arg < -1.0) arg = -1.0;
////	double _r=std::cos(arg);
////	return(_r);
////}
}



//--------------------------------------------
std::vector<fastjet::PseudoJet> make_PseudoJet_constituents( Jet* jet )
	//--------------------------------------------
{
	std::vector<fastjet::PseudoJet> particles;

	for( int consti_index = 0; consti_index < jet->Constituents.GetEntriesFast(); consti_index++ )
	//for( int consti_index = 0; consti_index < jet->Particles.GetEntriesFast(); consti_index++ )
	{
		TObject *object = jet->Constituents.At(consti_index);
		//TObject *object = jet->Particles.At(consti_index);

		// Check if the constituent is accessible
		//cout << object->IsA() << endl;
		//ShowMessage("jet pt",jet->PT);
		//ShowMessage("num",consti_index);
		if(object == 0) 
		{
			continue;
		}

		if(object->IsA() == GenParticle::Class())
		{
		//	ShowMessage("1");
			GenParticle *part = (GenParticle*) object;

			if( part->PID == 23 )
			{
				std::cout << "get Z boson" << std::endl;
				::exit(0);
			}

			fastjet::PseudoJet fastjet_part( part->Px, part->Py, part->Pz, part->E );
			fastjet_part.set_user_info( new PseudoJetInfo(part->PID, part->Charge, part->Status, part->IsPU, part->Mass) );
			particles.push_back( fastjet_part );
		}
		else if(object->IsA() == Track::Class())
		{
			//ShowMessage("2");
			Track *track = (Track*) object;

			fastjet::PseudoJet fastjet_part( track->P4().X(), track->P4().Y(), track->P4().Z(), track->P4().T() );
			fastjet_part.set_user_info( new PseudoJetInfo(track->PID, track->Charge, 0, 0, 0.0) );
			particles.push_back( fastjet_part );
		}
		else if(object->IsA() == Tower::Class())
		{
			//ShowMessage("3");
			Tower *tower = (Tower*) object;

			fastjet::PseudoJet fastjet_part( tower->P4().X(), tower->P4().Y(), tower->P4().Z(), tower->P4().T() );
			fastjet_part.set_user_info( new PseudoJetInfo(0, 0, 0, 0, 0.0) );
			particles.push_back( fastjet_part );
		}
		else if(object->IsA() == Electron::Class())
		{
		//	ShowMessage("4");
			Electron *electron = (Electron*) object;

			fastjet::PseudoJet fastjet_part( electron->P4().X(), electron->P4().Y(), electron->P4().Z(), electron->P4().T() );
			fastjet_part.set_user_info( new PseudoJetInfo(electron->Charge*(-11), electron->Charge, 0, 0, 0.0) );
			particles.push_back( fastjet_part );
		}
		else if(object->IsA() == Muon::Class())
		{
		//	ShowMessage("5");
			Muon *muon = (Muon*) object;

			fastjet::PseudoJet fastjet_part( muon->P4().X(), muon->P4().Y(), muon->P4().Z(), muon->P4().T() );
			fastjet_part.set_user_info( new PseudoJetInfo(muon->Charge*(-13), muon->Charge, 0, 0, 0.0) );
			particles.push_back( fastjet_part );
		}
		else
		{
			std::cout << "object is not GenParticle | Track | Tower" << std::endl;
			::exit(0);
		}
	}//end for index

	return particles;

}//end make_PseudoJet_constituents






//--------------------------------------------
int n_pos_track( const std::vector<fastjet::PseudoJet> & constituents )
	//--------------------------------------------
{
	int npos_track = 0;

	for( int index = 0; index < constituents.size(); index++ )
	{
		fastjet::PseudoJet constituent = constituents[index];
		int charge = constituent.user_info<PseudoJetInfo>().Charge;
		if( charge > 0 )
		{
			npos_track++;
		}
	}

	return npos_track;

}//end n_pos_track




//--------------------------------------------
int n_neg_track( const std::vector<fastjet::PseudoJet> & constituents )
	//--------------------------------------------
{
	int nneg_track = 0;

	for( int index = 0; index < constituents.size(); index++ )
	{
		fastjet::PseudoJet constituent = constituents[index];
		int charge = constituent.user_info<PseudoJetInfo>().Charge;
		if( charge < 0 )
		{
			nneg_track++;
		}
	}

	return nneg_track;

}//end n_neg_track



//--------------------------------------------
int n_tower( const std::vector<fastjet::PseudoJet> & constituents )
	//--------------------------------------------
{
	int ntower = 0;

	for( int index = 0; index < constituents.size(); index++ )
	{
		fastjet::PseudoJet constituent = constituents[index];
		int charge = constituent.user_info<PseudoJetInfo>().Charge;
		if( charge == 0 )
		{
			ntower++;
		}
	}

	return ntower;

}//end ntower




//--------------------------------------------
double get_multipole_moment( fastjet::PseudoJet jet, std::vector<fastjet::PseudoJet> constituents )
	//--------------------------------------------
{
	fastjet::PseudoJet beta_J(jet.px()/jet.e(), jet.py()/jet.e(), jet.pz()/jet.e(), 1.0);
	fastjet::PseudoJet beta_L(0.0, 0.0, jet.pz()/jet.e(), 1.0);
	fastjet::PseudoJet jet_copy = jet;
	jet_copy.unboost(beta_L);
	fastjet::PseudoJet beta_T(jet_copy.px()/jet_copy.e(), jet_copy.py()/jet_copy.e(), 0.0, 1.0);

	std::valarray<double> sum_mom(4);
	//cout << sum_mom[0] << ", " << sum_mom[1] << ", " << sum_mom[2] << ", " << sum_mom[3] << endl;

	std::vector<fastjet::PseudoJet> restsubjets = constituents;
	//cout << restsubjets.size() << endl;
	double obs = 0.0;
	for( int index = 0; index < restsubjets.size(); index++ )
	{

		//----directly boost to jet rest frame
		//restsubjets[index].unboost(beta_J);
		//----or boost to jet central rapidity frame then to rest frame
		restsubjets[index].unboost(beta_L);
		restsubjets[index].unboost(beta_T);

		fastjet::PseudoJet component = restsubjets[index];
		//if( index == 0 )
		//  {
		//  cout << "first: " << component.px() << ", " << component.py() << ", " << component.pz() << ", " << component.e() << endl;
		//  }
		double theta = 2*atan(exp(-component.pseudorapidity()));
		//cout << "theta: " << theta << endl;
		//double phi = component.phi_std();
		double phi = component.phi();
		//cout << "phi: " << component.phi() << " or " << component.phi_std() << endl;
		double x = phi*180.0/fastjet::pi;
		double y = (theta-fastjet::pi/2.0)*180.0/fastjet::pi;
		//cout << "x, y: " << x << ", " << y << endl;
		//obs += component.user_info<PseudoJetInfo>().Charge * component.E() * (3*cos(theta)*cos(theta)-1)*sin(phi) / jet->Mass;
		obs += pow(component.E(),0.1) * sin(theta)*cos(theta) / pow(jet.m(),0.1);
		//hist_rest->Fill( x, y, component.E() );
		//hist_rest->Fill( x, y, 1 );

		sum_mom += component.four_mom();
	}//end for index
	//cout << sum_mom[0] << ", " << sum_mom[1] << ", " << sum_mom[2] << ", " << sum_mom[3] << endl;
	//hist_rest->Draw("aitoff");
	//cc.SaveAs("test.eps");
	//::exit(0);

	return obs;

}//end get_multipole_moment




//--------------------------------------------
double get_multipole_moment_new( fastjet::PseudoJet jet, std::vector<fastjet::PseudoJet> constituents )
	//--------------------------------------------
{
	fastjet::PseudoJet beta_J(jet.px()/jet.e(), jet.py()/jet.e(), jet.pz()/jet.e(), 1.0);

	fastjet::PseudoJet beta_L(0.0, 0.0, jet.pz()/jet.e(), 1.0);
	fastjet::PseudoJet jet_copy = jet;
	jet_copy.unboost(beta_L);
	fastjet::PseudoJet beta_T(jet_copy.px()/jet_copy.e(), jet_copy.py()/jet_copy.e(), 0.0, 1.0);

	double vecx = jet_copy.px()/jet_copy.e();
	double vecy = jet_copy.py()/jet_copy.e();
	double vecxy = sqrt(vecx*vecx+vecy*vecy);
	vecx /= vecxy;
	vecy /= vecxy;

	std::vector<fastjet::PseudoJet> restsubjets = constituents;

	std::complex <double> complexi(0,1);
	std::complex <double> Y10, Y1p1, Y1m1;
	std::complex <double> a10(0,0), a1p1(0,0), a1m1(0,0);
	std::complex <double> Y20, Y2p1, Y2m1, Y2p2, Y2m2;
	std::complex <double> a20(0,0), a2p1(0,0), a2m1(0,0), a2p2(0,0), a2m2(0,0);
	std::complex <double> Y30, Y3p1, Y3m1, Y3p2, Y3m2, Y3p3, Y3m3;
	std::complex <double> a30(0,0), a3p1(0,0), a3m1(0,0), a3p2(0,0), a3m2(0,0), a3p3(0,0), a3m3(0,0);

	for( int index = 0; index < restsubjets.size(); index++ )
	{

		//----directly boost to jet rest frame
		//restsubjets[index].unboost(beta_J);
		//----or boost to jet central rapidity frame then to rest frame
		restsubjets[index].unboost(beta_L);
		restsubjets[index].unboost(beta_T);

		fastjet::PseudoJet component_temp = restsubjets[index];

		fastjet::PseudoJet component = fastjet::PseudoJet( 
				component_temp.px()*vecx+component_temp.py()*vecy,
				-component_temp.px()*vecy+component_temp.py()*vecx,
				component_temp.pz(), component_temp.e() );

		double theta = 2*atan(exp(-component.pseudorapidity()));
		//cout << "theta: " << theta << endl;

		//double phi = component.phi_std();
		double phi = component.phi();
		//cout << "phi: " << component.phi() << " or " << component.phi_std() << endl;
		std::complex <double> ephi = cos(phi)+complexi*sin(phi);
		std::complex <double> cephi = cos(phi)-complexi*sin(phi);

		Y10 = 1/2.0*sqrt(3/fastjet::pi)*cos(theta);
		Y1p1 = -1/2.0*sqrt(3/2.0/fastjet::pi)*sin(theta)*ephi;
		Y1m1 = 1/2.0*sqrt(3/2.0/fastjet::pi)*sin(theta)*cephi;

		Y20 = 1/4.0*sqrt(5/fastjet::pi)*(3*cos(theta)*cos(theta)-1);
		Y2p1 = -1/2.0*sqrt(15/2.0/fastjet::pi)*sin(theta)*cos(theta)*ephi;
		Y2m1 = 1/2.0*sqrt(15/2.0/fastjet::pi)*sin(theta)*cos(theta)*cephi;
		Y2p2 = 1/4.0*sqrt(15/2.0/fastjet::pi)*sin(theta)*sin(theta)*ephi*ephi;
		Y2m2 = 1/4.0*sqrt(15/2.0/fastjet::pi)*sin(theta)*sin(theta)*cephi*cephi;

		Y30 = 1/4.0*sqrt(7/fastjet::pi)*(5*cos(theta)*cos(theta)*cos(theta)-3*cos(theta));
		Y3p1 = -1/8.0*sqrt(21/fastjet::pi)*ephi*sin(theta)*(5*cos(theta)*cos(theta)-1);
		Y3m1 = 1/8.0*sqrt(21/fastjet::pi)*cephi*sin(theta)*(5*cos(theta)*cos(theta)-1);
		Y3p2 = 1/4.0*sqrt(105/2.0/fastjet::pi)*ephi*ephi*sin(theta)*sin(theta)*cos(theta);
		Y3m2 = 1/4.0*sqrt(105/2.0/fastjet::pi)*cephi*cephi*sin(theta)*sin(theta)*cos(theta);
		Y3p2 = -1/8.0*sqrt(35/fastjet::pi)*ephi*ephi*ephi*sin(theta)*sin(theta)*sin(theta);
		Y3m2 = 1/8.0*sqrt(35/fastjet::pi)*cephi*cephi*cephi*sin(theta)*sin(theta)*sin(theta);

		//obs += component.user_info<PseudoJetInfo>().Charge * component.E() * (3*cos(theta)*cos(theta)-1)*sin(phi) / jet->Mass;
		double kappa = -0.1;
		//correlation
		//double corr = component.user_info<PseudoJetInfo>().Charge * pow(component.E()/jet.m(),kappa);
		double corr = pow(component.E()/jet.m(),kappa);
		a10 += corr * Y10;
		a1p1 += corr * Y1p1;
		a1m1 += corr * Y1m1;

		a20 += corr * Y20;
		a2p1 += corr * Y2p1;
		a2m1 += corr * Y2m1;
		a2p2 += corr * Y2p2;
		a2m2 += corr * Y2m2;

		a30 += corr * Y30;
		a3p1 += corr * Y3p1;
		a3m1 += corr * Y3m1;
		a3p2 += corr * Y3p2;
		a3m2 += corr * Y3m2;
		a3p3 += corr * Y3p3;
		a3m3 += corr * Y3m3;

	}//end for index

	double C1 = real( 1/(2.0*1+1.0)*( a10*conj(a10)
				+a1p1*conj(a1p1)+a1m1*conj(a1m1) ) );
	//cout << "C1: " << C1 << endl;
	C1 = sqrt(C1);

	double C2 = real( 1/(2.0*2+1.0)*( a20*conj(a20)
				+a2p1*conj(a2p1)+a2m1*conj(a2m1) 
				+a2p2*conj(a2p2)+a2m2*conj(a2m2) ) );
	//cout << "C2: " << C2 << endl;
	C2 = sqrt(C2);

	double C3 = real( 1/(2.0*3+1.0)*( a30*conj(a30)
				+a3p1*conj(a3p1)+a3m1*conj(a3m1) 
				+a3p2*conj(a3p2)+a3m2*conj(a3m2)
				+a3p3*conj(a3p3)+a3m3*conj(a3m3) ) );
	//cout << "C3: " << C3 << endl;
	C3 = sqrt(C3);

	return C2;

}//end get_multipole_moment_new


