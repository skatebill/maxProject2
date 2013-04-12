/**********************************************************************
 *<
	FILE: maxProject2.cpp

	DESCRIPTION:	Appwizard generated plugin

	CREATED BY: 

	HISTORY: 

 *>	Copyright (c) 2003, All Rights Reserved.
 **********************************************************************/

#include "maxProject2.h"
#include <conio.h>
#include <IGame\IGame.h>
#include <iostream>
#include "IGame\IGameModifier.h"
#include "IGame\IGameControl.h"
#include "decomp.h"

#define maxProject2_CLASS_ID	Class_ID(0x5ca3ec45, 0xb3a7f23d)
class bone{
private:
	bone* parent;
public:
	bone(bone& p){parent=&p;}



};
class maxProject2 : public SceneExport {
	public:
		
		static HWND hParams;
		
		int				ExtCount();					// Number of extensions supported
		const TCHAR *	Ext(int n);					// Extension #n (i.e. "3DS")
		const TCHAR *	LongDesc();					// Long ASCII description (i.e. "Autodesk 3D Studio File")
		const TCHAR *	ShortDesc();				// Short ASCII description (i.e. "3D Studio")
		const TCHAR *	AuthorName();				// ASCII Author name
		const TCHAR *	CopyrightMessage();			// ASCII Copyright message
		const TCHAR *	OtherMessage1();			// Other message #1
		const TCHAR *	OtherMessage2();			// Other message #2
		unsigned int	Version();					// Version number * 100 (i.e. v3.01 = 301)
		void			ShowAbout(HWND hWnd);		// Show DLL's "About..." box

		BOOL SupportsOptions(int ext, DWORD options);
		int				DoExport(const TCHAR *name,ExpInterface *ei,Interface *i, BOOL suppressPrompts=FALSE, DWORD options=0);

		//Constructor/Destructor
		maxProject2();
		~maxProject2();		

};



class maxProject2ClassDesc : public ClassDesc2 {
	public:
	int 			IsPublic() { return TRUE; }
	void *			Create(BOOL loading = FALSE) { return new maxProject2(); }
	const TCHAR *	ClassName() { return GetString(IDS_CLASS_NAME); }
	SClass_ID		SuperClassID() { return SCENE_EXPORT_CLASS_ID; }
	Class_ID		ClassID() { return maxProject2_CLASS_ID; }
	const TCHAR* 	Category() { return GetString(IDS_CATEGORY); }

	const TCHAR*	InternalName() { return _T("maxProject2"); }	// returns fixed parsable name (scripter-visible name)
	HINSTANCE		HInstance() { return hInstance; }					// returns owning module handle
	

};

static maxProject2ClassDesc maxProject2Desc;
ClassDesc2* GetmaxProject2Desc() { return &maxProject2Desc; }





INT_PTR CALLBACK maxProject2OptionsDlgProc(HWND hWnd,UINT message,WPARAM wParam,LPARAM lParam) {
	static maxProject2 *imp = NULL;

	switch(message) {
		case WM_INITDIALOG:
			imp = (maxProject2 *)lParam;
			CenterWindow(hWnd,GetParent(hWnd));
			return TRUE;

		case WM_CLOSE:
			EndDialog(hWnd, 0);
			return 1;
	}
	return 0;
}


//--- maxProject2 -------------------------------------------------------
maxProject2::maxProject2()
{

}

maxProject2::~maxProject2() 
{

}

int maxProject2::ExtCount()
{
	//TODO: Returns the number of file name extensions supported by the plug-in.
	return 1;
}

const TCHAR *maxProject2::Ext(int n)
{		
	//TODO: Return the 'i-th' file name extension (i.e. "3DS").
	return _T("test");
}

const TCHAR *maxProject2::LongDesc()
{
	//TODO: Return long ASCII description (i.e. "Targa 2.0 Image File")
	return _T("");
}
	
const TCHAR *maxProject2::ShortDesc() 
{			
	//TODO: Return short ASCII description (i.e. "Targa")
	return _T("");
}

const TCHAR *maxProject2::AuthorName()
{			
	//TODO: Return ASCII Author name
	return _T("");
}

const TCHAR *maxProject2::CopyrightMessage() 
{	
	// Return ASCII Copyright message
	return _T("");
}

const TCHAR *maxProject2::OtherMessage1() 
{		
	//TODO: Return Other message #1 if any
	return _T("");
}

const TCHAR *maxProject2::OtherMessage2() 
{		
	//TODO: Return other message #2 in any
	return _T("");
}

unsigned int maxProject2::Version()
{				
	//TODO: Return Version number * 100 (i.e. v3.01 = 301)
	return 100;
}

void maxProject2::ShowAbout(HWND hWnd)
{			
	// Optional
}

BOOL maxProject2::SupportsOptions(int ext, DWORD options)
{
	// TODO Decide which options to support.  Simply return
	// true for each option supported by each Extension 
	// the exporter supports.

	return TRUE;
}

using namespace std;
int	maxProject2::DoExport(const TCHAR *name,ExpInterface *ei,Interface *i, BOOL suppressPrompts, DWORD options)
{
	//TODO: Implement the actual file Export here and 
	//		return TRUE If the file is exported properly

	AllocConsole();
	 _cprintf( "Export Begin\n" );//记得#include <conio.h>
	IGameConversionManager * cm = GetConversionManager();
	cm->SetCoordSystem( IGameConversionManager::IGAME_D3D );
	
	IGameScene* pSce=GetIGameInterface();

	pSce->InitialiseIGame(false);
	pSce->SetStaticFrame(0);

	int num=pSce->GetTopLevelNodeCount();
//	_cprintf("node count %d \n",num);
//	_cprintf("%s \n",name);

	TSTR outBuf;
	int matCount = pSce->GetRootMaterialCount();
//	_cprintf("MaterialCount count %d \n",matCount);
	FILE* file=freopen(name, "w", stdout);

	if(!file)
	{
		return FALSE;
	}
	/*cout<<"MatreialRootList Num: "<<matCount<<endl;
	
	for(int j =0;j<matCount;j++){	
		IGameMaterial* rootmat=pSce->GetRootMaterial(j);
		int num=rootmat->GetSubMaterialCount();
		TCHAR* name= rootmat->GetMaterialName();
		cout<<"\tMatrial mutiType :"<<rootmat->IsMultiType()<<endl;
		cout<<"\ttMatreialRoot name : "<<name<<endl;
		cout<<"\t\tMatreialRoot #"<<j<<" ----SubMatNum : "<<num<<endl;
		for(int i=0;i<num;i++){
			IGameMaterial* submat=rootmat->GetSubMaterial(i);
			cout<<"\t\tMatrial mutiType"<<submat->IsMultiType()<<endl;
			cout<<"\t\tSubMatName : "<<submat->GetMaterialName()<<endl;
			cout<<"\t\tSubMatSubNum : "<<submat->GetSubMaterialCount()<<endl;
		}
	}*/
	int nodecount=pSce->GetTopLevelNodeCount();
	int frame=pSce->GetSceneStartTime();
/*	cout<<pSce->GetSceneStartTime()<<endl;
	cout<<pSce->GetSceneEndTime()<<endl;
	cout<<GetFrameRate()<<endl;*/
//	cout<<"top level node count:"<<nodecount<<endl;
	for(int i=0;i<nodecount;i++)
	{
		IGameNode* topnode=pSce->GetTopLevelNode(i);
		IGameObject* obj=topnode->GetIGameObject();
//		cout<<"\tnode #:"<<i<<endl;
		if(obj->GetIGameType()==IGameObject::IGAME_BONE)
		{
/*	
			cout<<"\t\t bone"<<endl;
			
			IGameSupportObject * hO = (IGameSupportObject*)obj;
			IGameMesh * hm = hO->GetMeshObject();
			if(hm->InitializeData())
			{
				int num = hm->GetNumberOfVerts();
				cout<<"\t\t number of vertex : "<<num<<endl;
				cout<<"\t\t number of texcoord : "<<hm->GetNumberOfTexVerts()<<endl;
				cout<<"\t\t number of normals : "<<hm->GetNumberOfNormals()<<endl;
			}
			if(obj->GetIGameSkin()){
				cout<<"\t\tHAS SKIN"<<endl;
			}
*/
			IGameControl* con=topnode->GetIGameControl();

			IGameKeyTab keys;
			con->get
			con->GetFullSampledKeys(keys,GetFrameRate(),IGAME_ROT);
			int num=keys.Count();

			_cprintf( "keys count %d \n",keys.Count());//记得#include <conio.h>
	//		if(num>1)
			//	num=1;
			for(int i=0;i<num;i++){
				Matrix3 t=keys[i].sampleKey.gval.ExtractMatrix3();

				_cprintf("\tkey frame time : %d\n",keys[i].t);
				_cprintf("\tkey frame pos : %d\n",keys[i].t/pSce->GetSceneTicks());
				AffineParts ap;
				
				float rotAngle;
				Point3 rotAxis;
				float scaleAxAngle;	
				Point3 scaleAxis;

				decomp_affine(t, &ap);

				
					// Quaternions are dumped as angle axis.
				AngAxisFromQ(ap.q, &rotAngle, rotAxis);
				AngAxisFromQ(ap.u, &scaleAxAngle, scaleAxis);

				/*_cprintf("\ttrans%f %f %f\n",ap.t.x,ap.t.y,ap.t.z);			
				_cprintf("\trot%f %f %f %f\n",rotAxis.x, rotAxis.y, rotAxis.z, rotAngle);
				_cprintf("%f %f %f %f %f %f %f\n", ap.k.x, ap.k.y, ap.k.z, scaleAxis.x,scaleAxis.y,scaleAxis.z, scaleAxAngle);*/

			}


		}else if(obj->GetIGameType()==IGameObject::IGAME_MESH){
		//	cout<<"\t\t mesh"<<endl;
			
			IGameMesh * hm = (IGameMesh*)obj;


			IGameSkin* skin=obj->GetIGameSkin();
		/*	if(skin){
				cout<<"\t\tHAS SKIN"<<endl;

				if(skin->GetSkinType()== IGameSkin::IGAME_PHYSIQUE)
					cout<<"\t\t\tPhysique"<<endl;
				else
					cout<<"\t\t\tmaxskin"<<endl;
				int bn=skin->GetNumberOfBones(0);
				cout<<"\t\t\t number of bones for 0 :"<<skin->GetNumberOfBones(0)<<endl;
				for(int i=0;i<bn;i++){
					cout<<"\t\t\t"<<skin->GetBone(0,i)->GetName()<<endl;
					cout<<"\t\t\t"<<skin->GetWeight(0,i)<<endl;
				}

				cout<<"\t\t\t total number of bones :"<<skin->GetTotalBoneCount()<<endl;

			}*/
			if(hm->InitializeData())
			{
				cout<<"m"<<endl;
				int num = hm->GetNumberOfVerts();
			/*	cout<<"\t\t number of vertex : "<<num<<endl;
				cout<<"\t\t number of texcoord : "<<hm->GetNumberOfTexVerts()<<endl;
				cout<<"\t\t number of normals : "<<hm->GetNumberOfNormals()<<endl;*/
				for(int iv=0;iv<num;iv++){
					Point3 v=hm->GetVertex(iv);
					cout<<"v "<<v.x<<" "<<v.y<<" "<<v.z<<endl;
					if(skin)
					{
						int bonenum=skin->GetNumberOfBones(iv);
						for(int bi=0;bi<bonenum;bi++)
						{
							INode* bone=skin->GetBone(iv,bi);
							int boneid=skin->GetBoneID(iv,bi);
							bone->GetNodeTM(0);
							cout<<"\t bone ID : "<<boneid<<" bone weight : "<<skin->GetWeight(iv,bi)<<endl;
						}
					}
				}
				cout<<"mi"<<endl;
				int tn=hm->GetNumberOfFaces();
				for(int tv=0;tv<tn;tv++){
					FaceEx* f=hm->GetFace(tv);
					cout<<"i "<<f->vert[0]<<" "<<f->vert[1]<<" "<<f->vert[2]<<endl;
				}
			}
		}else{
//			cout<<"\t\t else"<<endl;
		}

	}


	/*if(!suppressPrompts)
		DialogBoxParam(hInstance, 
				MAKEINTRESOURCE(IDD_PANEL), 
				GetActiveWindow(), 
				maxProject2OptionsDlgProc, (LPARAM)this);*/
	fclose(file);
	return TRUE;
}


