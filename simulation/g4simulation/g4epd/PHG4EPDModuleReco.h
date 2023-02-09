// Tell emacs that this is a C++ source
//  -*- C++ -*-.
#ifndef G4EPD_PHG4EPDMODULERECO_H
#define G4EPD_PHG4EPDMODULERECO_H

#include <phparameter/PHParameterInterface.h>

#include <fun4all/SubsysReco.h>

#include <array>
#include <vector>
#include <cmath>
#include <string>

class PHCompositeNode;

class PHG4EPDModuleReco : public SubsysReco, public PHParameterInterface
{
 public:
    PHG4EPDModuleReco(const std::string &name = "EpdModuleReco");

  ~PHG4EPDModuleReco() override {}

  //! module initialization
  int InitRun(PHCompositeNode *topNode) override;

  //! event processing
  int process_event(PHCompositeNode *topNode) override;

//! Reset after every event
  int ResetEvent(PHCompositeNode * /*topNode*/) override;

  void SetDefaultParameters() override;

  void Detector(const std::string &d);
    
  std::string
  get_epd_sim_tower_node_prefix() const
  {
      return m_EPDSimTowerNodePrefix;
  }

  void
  set_epd_sim_tower_node_prefix(const std::string &epdsimTowerNodePrefix)
  {
      m_EPDSimTowerNodePrefix = epdsimTowerNodePrefix;
  }
    
  std::string
  get_epd_calib_tower_node_prefix() const
  {
      return m_EPDCalibTowerNodePrefix;
  }

  void
  set_epd_calib_tower_node_prefix(const std::string &epdcalibTowerNodePrefix)
  {
     m_EPDCalibTowerNodePrefix = epdcalibTowerNodePrefix;
  }
    
  void set_EPD_MPV_in_GeV(const double epdmpv) { _epdmpv = epdmpv; }

  void set_timing_window(const double tmi, const double tma);

 private:

  int Getrmap(int rindex);
  int Getphimap(int phiindex);
  void CreateNodes(PHCompositeNode *topNode);
    
  std::string detector;
  std::string hitnodename;
  std::string m_EPDSimTowerNodePrefix;
  std::string m_EPDCalibTowerNodePrefix;

  std::string m_TowerInfoNodeName;
  std::string m_TowerInfoNodeName_calib;
  std::array<std::array<std::array<double,31>,12>,2> epd_tile_e = {};
  std::array<std::array<std::array<double,31>,12>,2>  epd_tile_calib_e = {};

  double _epdmpv = 1.;    
    
  double tmin = NAN;
  double tmax = NAN;
  double m_DeltaT = NAN;
  
};

#endif

