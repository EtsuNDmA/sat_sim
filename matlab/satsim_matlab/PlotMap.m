% Plot a circular orbit
figure
m_proj('miller','lat',82);
m_coast('color',[0 .6 0]);
m_line(svlon/d2r,svlatgc/d2r,'linewi',2,'color','r');
m_grid('linestyle','none','box','fancy','tickdir','out');