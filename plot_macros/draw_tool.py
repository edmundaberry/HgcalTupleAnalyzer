import ROOT as r 
from array import array

class DrawTool:
    
    def __init__(self):
    
        self.cluster_graphs_ep = []
        self.cluster_graphs_xy = []
        self.cluster_graphs_xz = []
        self.cluster_graphs_yz = []
        
        self.rechit_graphs_ep = []
        self.rechit_graphs_xy = []
        self.rechit_graphs_xz = []
        self.rechit_graphs_yz = []
        self.pfcand_graphs_ep = []
        self.subjet_graph_ep = r.TGraph()
        
        self.draw = False

        self.legend = r.TLegend()
        
        self.multigraph_ep = r.TMultiGraph("ep", "#eta#phi")
        self.multigraph_xy = r.TMultiGraph("xy", "xy")
        self.multigraph_xz = r.TMultiGraph("xz", "xz")
        self.multigraph_yz = r.TMultiGraph("yz", "yz")
        self.multigraph_ep_final = r.TMultiGraph("ep_final", "ep_final")

        self.colors = list ( range ( 1, 100 ))
        
    def makeLegend(self, jet):
        
        self.legend.AddEntry( self.subjet_graph_ep, "Subjets", "p")
        for icand in range (0, len(self.cluster_graphs_xy)):
            cand = jet.cands[icand]
            pfcand_graph  = self.pfcand_graphs_ep[icand]
            cluster_graph = self.cluster_graphs_xy[icand]
            rechit_graph = self.rechit_graphs_xy[icand]
            
            name = "PFCand " + str(icand+1) + ": " + cand.idname + ", pt = %1.1f" % cand.pt + " GeV"
            self.legend.AddEntry( pfcand_graph, name, "p" )
            self.legend.AddEntry( cluster_graph, "Clusters of " + name, "p" )
            self.legend.AddEntry( rechit_graph , "RecHits of " + name, "p" )
            
    def makeGraphs(self, jet):
        
        self.cluster_graphs_ep = []
        self.cluster_graphs_xy = []
        self.cluster_graphs_xz = []
        self.cluster_graphs_yz = []

        self.rechit_graphs_ep = []
        self.rechit_graphs_xy = []
        self.rechit_graphs_xz = []
        self.rechit_graphs_yz = []

        self.pfcand_graphs_ep = []

        subjet_e_list = []
        subjet_p_list = []
        
        for subjet in jet.subjets:
            subjet_e_list.append ( subjet.eta )
            subjet_p_list.append ( subjet.phi )

        self.subjet_graph_ep = r.TGraph(len(subjet_e_list), array('f', subjet_e_list), array('f', subjet_p_list) )
        self.subjet_graph_ep.SetMarkerColor(r.kBlack)
        self.subjet_graph_ep.SetMarkerStyle(3) 

        for icand, cand in enumerate(jet.cands):
            clusters = cand.clusters
            n_clusters = len ( clusters ) 
            n_rechits = 0
            if not clusters: continue

            cluster_e_list = []
            cluster_p_list = []
            cluster_x_list = []
            cluster_y_list = []
            cluster_z_list = []

            rechit_e_list = []
            rechit_p_list = []
            rechit_x_list = []
            rechit_y_list = []
            rechit_z_list = []

            pfcand_e_list = [ cand.eta ]
            pfcand_p_list = [ cand.phi ]
 
            for cluster in clusters:
                cluster_e_list.append ( cluster.Eta )
                cluster_p_list.append ( cluster.Phi )
                cluster_x_list.append ( cluster.X ) 
                cluster_y_list.append ( cluster.Y ) 
                cluster_z_list.append ( abs(cluster.Z) ) 

                rechits = cluster.rechits

                n_rechits += len ( rechits ) 

                for rechit in rechits:
                    rechit_e_list.append ( rechit.Eta )
                    rechit_p_list.append ( rechit.Phi )
                    rechit_x_list.append ( rechit.X )
                    rechit_y_list.append ( rechit.Y )
                    rechit_z_list.append ( abs(rechit.Z) )

            self.draw = True

            self.pfcand_graphs_ep.append  (r.TGraph( 1         , array('f', pfcand_e_list ), array('f', pfcand_p_list )))
            
            self.cluster_graphs_ep.append (r.TGraph( n_clusters, array('f', cluster_e_list), array('f', cluster_p_list)))
            self.cluster_graphs_xy.append (r.TGraph( n_clusters, array('f', cluster_x_list), array('f', cluster_y_list)))
            self.cluster_graphs_xz.append (r.TGraph( n_clusters, array('f', cluster_z_list), array('f', cluster_x_list)))
            self.cluster_graphs_yz.append (r.TGraph( n_clusters, array('f', cluster_z_list), array('f', cluster_y_list)))
        
            self.rechit_graphs_ep.append (r.TGraph( n_rechits, array('f', rechit_e_list), array('f', rechit_p_list)))
            self.rechit_graphs_xy.append (r.TGraph( n_rechits, array('f', rechit_x_list), array('f', rechit_y_list)))
            self.rechit_graphs_xz.append (r.TGraph( n_rechits, array('f', rechit_z_list), array('f', rechit_x_list)))
            self.rechit_graphs_yz.append (r.TGraph( n_rechits, array('f', rechit_z_list), array('f', rechit_y_list)))
        
            self.pfcand_graphs_ep [-1].SetMarkerColor(self.colors[icand])
            self.cluster_graphs_ep[-1].SetMarkerColor(self.colors[icand])
            self.cluster_graphs_xy[-1].SetMarkerColor(self.colors[icand])
            self.cluster_graphs_xz[-1].SetMarkerColor(self.colors[icand])
            self.cluster_graphs_yz[-1].SetMarkerColor(self.colors[icand])

            if cand.idnumber != 4:
                self.cluster_graphs_ep[-1].SetMarkerStyle(20)
                self.cluster_graphs_xy[-1].SetMarkerStyle(20)
                self.cluster_graphs_xz[-1].SetMarkerStyle(20)
                self.cluster_graphs_yz[-1].SetMarkerStyle(20)
                self.pfcand_graphs_ep[-1].SetMarkerStyle(21)
            else:
                self.cluster_graphs_ep[-1].SetMarkerStyle(4)
                self.cluster_graphs_xy[-1].SetMarkerStyle(4)
                self.cluster_graphs_xz[-1].SetMarkerStyle(4)
                self.cluster_graphs_yz[-1].SetMarkerStyle(4)
                self.pfcand_graphs_ep[-1].SetMarkerStyle(25)
                
            self.rechit_graphs_ep[-1].SetMarkerColor(self.colors[icand])
            self.rechit_graphs_xy[-1].SetMarkerColor(self.colors[icand])
            self.rechit_graphs_xz[-1].SetMarkerColor(self.colors[icand])
            self.rechit_graphs_yz[-1].SetMarkerColor(self.colors[icand])

            self.multigraph_ep_final.Add ( self.pfcand_graphs_ep[-1] ) 
            
            self.multigraph_xy.Add ( self.cluster_graphs_xy[-1] ) 
            self.multigraph_xz.Add ( self.cluster_graphs_xz[-1] ) 
            self.multigraph_yz.Add ( self.cluster_graphs_yz[-1] ) 

            self.multigraph_ep.Add ( self.rechit_graphs_ep[-1] ) 
            self.multigraph_xy.Add ( self.rechit_graphs_xy[-1] ) 
            self.multigraph_xz.Add ( self.rechit_graphs_xz[-1] ) 
            self.multigraph_yz.Add ( self.rechit_graphs_yz[-1] ) 

        self.multigraph_ep_final.Add (self.subjet_graph_ep)            
        self.makeLegend(jet)

        
        
