% ---------------------------------------------------------------------
% EG author guidelines plus sample file for EG publication using LaTeX2e input
% D.Fellner, v1.17, Sep 23, 2010

\title[Interactive Visual Analysis of Cohort Study Data]%
      {Interactive Visual Analysis of Cohort Study Data}

% for anonymous conference submission please enter your SUBMISSION ID
% instead of the author's name (and leave the affiliation blank) !!
\author[Paul Klemm, Steffen Oeltze-Jafra, Kai Lawonn, Sylvia Gla{\ss}er, Katrin Hegenscheid, Henry V{\"o}lzke, Bernhard Preim]
       {Paul Klemm$^{1}$, Kai Lawonn$^{1}$, Sylvia Gla{\ss}er$^{1}$, Steffen Oeltze-Jafra$^{1}$, Katrin Hegenscheid$^{2}$, Henry V{\"o}lzke$^{2}$, Bernhard Preim$^{1}$
        \\
% For Computer Graphics Forum: Please use the abbreviation of your first name.
         $^1$Otto-von-Guericke University Magdeburg, Germany\\
         $^2$Ernst-Moritz-Arndt University Greifswald, Germany
%        $^2$ Another Department to illustrate the use in papers from authors
%             with different affiliations
       }

% ------------------------------------------------------------------------

% if the Editors-in-Chief have given you the data, you may uncomment
% the following five lines and insert it here
%
% \volume{27}   % the volume in which the issue will be published;
% \issue{1}     % the issue number of the publication
% \pStartPage{1}      % set starting page


%-------------------------------------------------------------------------
\begin{document}

\maketitle

\begin{abstract}
Epidemiological population studies impose information about a set of subjects (a cohort) to characterize disease-specific risk factors.
%%
Cohort studies comprise heterogenous variables (features) describing the medical condition as well as demographic and lifestyle factors.
%%
The data are analyzed using a priori defined hypotheses to find statistically significant correlations between features (associations).
%%
Modern cohort studies incorporate medical image data.
%%
The statistically driven epidemiological workflow only allows to determine associations between image-derived metrics, such as distances extracted from landmarks of the segmentation model.
\\\\
We propose methods for analyzing image- centric cohort study data with focus on assessing influences of organ shape.
%%
To account for epidemiological key requirements such as reproducibility and statistical resilience of results, the epidemiological workflow is analyzed and divided into different steps.
%%
Based on this analysis, an Interactive Visual Analysis (IVA) approach is proposed that enables epidemiologists to examine both image-based as well as non-image data, e.g., sociodemographic features and attributes derived from the image data.
%%
This approach enables hypotheses validation and generation by incorporating human pattern recognition as well as data mining methods.
%%
Using all reliable information from the image segmentation linked to non-image features aims to unveil associations by applying an iterative analysis approach.

\begin{classification} % according to http://www.acm.org/class/1998/
% ToDo: [high] Update Classification
\CCScat{Computer Graphics}{I.3.3}{Picture/Image Generation}{Line and curve generation}
\end{classification}

\end{abstract}
%-------------------------------------------------------------------------
\section{Introduction and Project Background}
Epidemiology characterizes the influence of causes to disease and health conditions of defined populations.
%%
Cohort studies are population-based studies involving usually large numbers of randomly selected individuals and comprising numerous attributes, ranging from self-reported interview data to results from various medical examinations, e.g., blood and urine samples (\emph{features}).
%%
Since recently, medical imaging has been used as an additional instrument to assess risk factors and potential prognostic information.
%%
The statistically driven epidemiological workflow only allows to determine \emph{associations} between image-derived metrics, such as distances extracted from landmarks of the segmentation model.
%%

This work is the result of a collaboration between epidemiologists of the Study of Health in Pomerania (SHIP) \cite{SHIP} and computer scientists of the University of Magdeburg under the umbrella of the DFG Project "Visual Analysis in Public Health".
%%
The focus lies on novel techniques for analyzing both image- and non-image data of cohort study data simultaneously.
%%
We took the following steps to achieve this goal.

\begin{itemize}
	\item Building a Interactive Visual Analysis (IVA) system which is based on analysis of the epidemiological workflow to allow rapid hypothesis validation- and generation \cite{Klemm2014VIS}.
	%%
	\item Combine shape variability visualization techniques with information visualizations of non-image data \cite{Klemm2014VIS}.
	%%
	\item Provide similarity measures and visualizations that involve associations between features out of the focus of the epidemiologists to allow for hypothesis generation \cite{Klemm2014BVM}.
	%%
	\item Use data mining to derive shape-based groups of subjects using clustering techniques \cite{Klemm2013VMV}.
	%%
	\item Use classification methods to derive insight into specific disease risk factors \cite{IVAPP}.
\end{itemize}
%
The proposed methods are introduced as part of an Interactive Visual Analysis approach presented in the following section.
%
All publications use a lumbar spine data set from the Study of Health in Pomerania \cite{SHIP}.
%
It consists of 6.753 subjects from two cohorts with 77 parameter compiled by domain experts.
%
The image data was segmented using a tetrahedron-based finite element model \cite{Rak2013}.

\section{Extending the Epidemiological Workflow}

\subsection{Epidemiological Workflow}

\subsection{Epidemiological Data}

\section{Visualization and Analysis of Lumbar Spine Canal Variability}

\section{Interactive Visual Analysis of Cohort Study Data}

\section{Conclusion and Future Work}

\bibliographystyle{style/eg-alpha-doi}

\bibliography{bibliography}

%-------------------------------------------------------------------------
\newpage

\end{document}
